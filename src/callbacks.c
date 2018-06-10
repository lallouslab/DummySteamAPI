#include <inttypes.h>
#include <stdint.h>

#include "CCallback.h"
#include "callbacks.h"
#include "debug.h"
#include "list.h"
#include "steam.h"
#include "utils.h"

struct call_output
{
	enum steam_callback_type type;
	steam_bool_t is_api_call : 1;
	steam_bool_t is_handled : 1;
	steam_bool_t io_failure : 1;
	steam_api_call_t api_call;
	void *data;
	int data_size;
};

struct api_call_result
{
	struct CCallbackBase *callback;
	steam_api_call_t api_call;
};

static steam_api_call_t last_api_call_id;

static struct list callbacks[STEAM_CALLBACK_TYPE_MAX];
static struct list api_call_results;

static struct list call_outputs;

int callbacks_init(void)
{
	last_api_call_id = 0;

	for (size_t i = 0; i < ARRAY_SIZE(callbacks); i++)
		list_init(&callbacks[i]);

	list_init(&api_call_results);
	list_init(&call_outputs);
	return 0;
}

void callbacks_register_callback(struct CCallbackBase *callback, enum steam_callback_type type)
{
	if (type >= STEAM_CALLBACK_TYPE_MAX)
		return;

	callback->type = type;
	callback->flags |= STEAM_CALLBACK_FLAGS_REGISTERED;

	list_lock(&callbacks[type]);
	list_push(&callbacks[type], &callback, sizeof(callback));
	list_unlock(&callbacks[type]);
}

void callbacks_unregister_callback(struct CCallbackBase *callback)
{
	if (callback->type >= STEAM_CALLBACK_TYPE_MAX)
		return;

	list_lock(&callbacks[callback->type]);

	for (struct list_elem *elem = list_head(&callbacks[callback->type]); elem; elem = list_next(elem))
	{
		struct CCallbackBase *c = *(struct CCallbackBase **)list_get_data(elem);

		if (c == callback)
		{
			list_remove(&callbacks[callback->type], elem);
			break;
		}
	}

	list_unlock(&callbacks[callback->type]);

	callback->flags &= ~STEAM_CALLBACK_FLAGS_REGISTERED;
}

void callbacks_register_api_call_result(struct CCallbackBase *callback, steam_api_call_t api_call)
{
	struct api_call_result call_result;

	if (callback->type >= STEAM_CALLBACK_TYPE_MAX)
		return;

	call_result.callback = callback;
	call_result.api_call = api_call;

	callback->flags |= STEAM_CALLBACK_FLAGS_REGISTERED;

	list_lock(&api_call_results);
	list_push(&api_call_results, &call_result, sizeof(call_result));
	list_unlock(&api_call_results);
}

static void unreg_api_call_result_unsafe(struct CCallbackBase *callback, struct list_elem *elem)
{
	if (elem)
		list_remove(&api_call_results, elem);

	callback->flags &= ~STEAM_CALLBACK_FLAGS_REGISTERED;
}

void callbacks_unregister_api_call_result(struct CCallbackBase *callback, steam_api_call_t api_call)
{
	struct list_elem *elem;

	if (callback->type >= STEAM_CALLBACK_TYPE_MAX)
		return;

	list_lock(&api_call_results);

	for (elem = list_head(&api_call_results); elem; elem = list_next(elem))
	{
		struct api_call_result *call_result = list_get_data(elem);
		struct CCallbackBase *c = call_result->callback;

		if (call_result->api_call != api_call)
			continue;

		if (c == callback)
			break;
	}

	unreg_api_call_result_unsafe(callback, elem);

	list_unlock(&api_call_results);
}

void callbacks_dispatch_callback_output(enum steam_callback_type type, void *data, size_t data_size)
{
	struct call_output out;

	if (type >= STEAM_CALLBACK_TYPE_MAX)
		return;

	out.type = type;
	out.is_api_call = STEAM_FALSE;
	out.is_handled = STEAM_FALSE;
	out.io_failure = STEAM_FALSE;
	out.api_call = 0;
	out.data = dsa_utils_memdup(data, data_size);
	out.data_size = data_size;

	list_lock(&call_outputs);
	list_push(&call_outputs, &out, sizeof(out));
	list_unlock(&call_outputs);
}

steam_api_call_t callbacks_dispatch_api_call_result_output(enum steam_callback_type type, steam_bool_t io_failure, void *data, size_t data_size)
{
	struct call_output out;

	if (type >= STEAM_CALLBACK_TYPE_MAX)
		return 0;

	out.type = type;
	out.is_api_call = STEAM_TRUE;
	out.is_handled = STEAM_FALSE;
	out.io_failure = io_failure;
	out.api_call = ++last_api_call_id;
	out.data = dsa_utils_memdup(data, data_size);
	out.data_size = data_size;

	list_lock(&call_outputs);
	list_push(&call_outputs, &out, sizeof(out));
	list_unlock(&call_outputs);

	return out.api_call;
}

static int remove_call_output_unsafe(struct list_elem *elem)
{
	struct call_output *out;

	out = list_get_data(elem);
	if (out->data)
	{
		free(out->data);
		out->data = NULL;
	}

	return list_remove(&call_outputs, elem);
}

static steam_bool_t api_call_result_get_output(steam_bool_t only_check, steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *io_failure)
{
	steam_bool_t result = STEAM_FALSE;
	struct list_elem *next_elem;

	if (io_failure)
		*io_failure = STEAM_FALSE;

	list_lock(&call_outputs);

	for (struct list_elem *elem = list_head(&call_outputs); elem; elem = next_elem)
	{
		struct call_output *out;

		next_elem = list_next(elem);

		out = list_get_data(elem);
		if (out->api_call != api_call)
			continue;

		if (!only_check)
		{
			if (out->data_size != data_size
					|| out->type != type_expected)
				continue;

			if (data)
				memcpy(data, out->data, out->data_size);
		}

		if (io_failure)
			*io_failure = out->io_failure;

		if (!only_check)
			remove_call_output_unsafe(elem);

		result = STEAM_TRUE;
		break;
	}

	list_unlock(&call_outputs);

	return result;
}

steam_bool_t callbacks_api_call_result_is_output_available(steam_api_call_t api_call, steam_bool_t *io_failure)
{
	return api_call_result_get_output(STEAM_TRUE, api_call, NULL, 0, 0, io_failure);
}

steam_bool_t callbacks_api_call_result_get_output(steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *io_failure)
{
	return api_call_result_get_output(STEAM_FALSE, api_call, data, data_size, type_expected, io_failure);
}

static steam_bool_t handle_callback_output(struct call_output *out)
{
	if (out->type >= STEAM_CALLBACK_TYPE_MAX)
		return STEAM_FALSE;

	if (out->is_api_call)
		return STEAM_FALSE;

	if (out->is_handled)
		return STEAM_TRUE;

	list_lock(&callbacks[out->type]);

	for (struct list_elem *elem = list_head(&callbacks[out->type]); elem; elem = list_next(elem))
	{
		struct CCallbackBase *callback;
		int size;

		callback = *(struct CCallbackBase **)list_get_data(elem);

		size = callback->vtbl->GetCallbackSizeBytes(callback);
		if (size != out->data_size)
		{
			DEBUG("Callback %s (%d) data size mismatch: expected %u != got %u", dsa_debug_steam_callback_type(out->type), out->type, out->data_size, size);
			continue;
		}

		callback->vtbl->Run0(callback, out->data);

		out->is_handled = STEAM_TRUE;
	}

	list_unlock(&callbacks[out->type]);

	return out->is_handled;
}

static steam_bool_t handle_api_call_result_output(struct call_output *out)
{
	struct list_elem *next_elem;

	if (out->type >= STEAM_CALLBACK_TYPE_MAX)
		return STEAM_FALSE;

	if (!out->is_api_call)
		return STEAM_FALSE;

	if (out->is_handled)
		return STEAM_TRUE;

	list_lock(&api_call_results);

	for (struct list_elem *elem = list_head(&api_call_results); elem; elem = next_elem)
	{
		struct api_call_result *call_result;
		struct CCallbackBase *callback;
		int size;

		next_elem = list_next(elem);

		call_result = list_get_data(elem);
		callback = call_result->callback;

		if (callback->type != out->type
				|| call_result->api_call != out->api_call)
			continue;

		size = callback->vtbl->GetCallbackSizeBytes(callback);
		if (size != out->data_size)
		{
			DEBUG("Call result #%" PRIu64 " %s (%u) data size mismatch: expected %u != got %u", out->api_call, dsa_debug_steam_callback_type(out->type), out->type, out->data_size, size);
			continue;
		}

		callback->vtbl->Run1(callback, out->data, out->io_failure, out->api_call);

		unreg_api_call_result_unsafe(callback, elem);

		out->is_handled = STEAM_TRUE;

	}

	list_unlock(&api_call_results);

	return out->is_handled;
}

void callbacks_run(void)
{
	struct list_elem *next_elem;

	list_lock(&call_outputs);

	for (struct list_elem *elem = list_head(&call_outputs); elem; elem = next_elem)
	{
		struct call_output *out = list_get_data(elem);

		next_elem = list_next(elem);

		if (out->type >= STEAM_CALLBACK_TYPE_MAX)
			continue;

		if (out->is_api_call)
			handle_api_call_result_output(out);
		else
			handle_callback_output(out);

		if (!out->is_handled)
			continue;

		remove_call_output_unsafe(elem);
	}

	list_unlock(&call_outputs);
}
