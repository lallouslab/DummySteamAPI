#include "callbacks.h"
#include "utils.h"

#include "CCallback.h"

/* CCallbackBase */

void CCallbackBase(struct CCallbackBase *iface)
{
	iface->vtbl = NULL;
	iface->flags = STEAM_CALLBACK_FLAGS_NONE;
	iface->type = 0;
}

enum steam_callback_type CCallbackBase_GetICallback(struct CCallbackBase *iface)
{
	return iface->type;
}

/* CCallResult */

static void CCallResult_Run0(struct CCallbackBase *iface, void *param)
{
	struct CCallResult *impl = CCallResult_from_CCallbackBase(iface);

	iface->vtbl->Run1(iface, STEAM_FALSE, impl->api_call, param);
}

static void CCallResult_Run1(struct CCallbackBase *iface, steam_bool_t io_failure, steam_api_call_t api_call, void *param)
{
	struct CCallResult *impl = CCallResult_from_CCallbackBase(iface);

	if (api_call != impl->api_call)
		return;

	impl->api_call = 0;
	impl->callback(impl->obj, param, io_failure);
}

static int CCallResult_GetCallbackSizeBytes(struct CCallbackBase *iface)
{
	struct CCallResult *impl = CCallResult_from_CCallbackBase(iface);

	return impl->data_size;
}

static const struct CCallbackBaseVtbl CCallResult_vtbl =
{
	.Run0 = CCallResult_Run0,
	.Run1 = CCallResult_Run1,
	.GetCallbackSizeBytes = CCallResult_GetCallbackSizeBytes
};

void CCallResult(struct CCallResult *iface, enum steam_callback_type type, size_t data_size)
{
	CCallbackBase(&iface->base);
	iface->base.vtbl = &CCallResult_vtbl;
	iface->base.type = type;
	iface->api_call = 0;
	iface->obj = NULL;
	iface->callback = NULL;
	iface->data_size = data_size;
}

void CCallResult_dtor(struct CCallResult *iface)
{
	CCallResult_Cancel(iface);
}

void CCallResult_Set(struct CCallResult *iface, steam_api_call_t api_call, void *obj, steam_api_call_callback_t callback)
{
	if (iface->api_call)
		callbacks_unregister_api_call_result(&iface->base, iface->api_call);

	iface->api_call = api_call;
	iface->obj = obj;
	iface->callback = callback;

	if (iface->api_call)
		callbacks_register_api_call_result(&iface->base, iface->api_call);
}

steam_bool_t CCallResult_IsActive(struct CCallResult *iface)
{
	return !!iface->api_call;
}

void CCallResult_Cancel(struct CCallResult *iface)
{
	if (!CCallResult_IsActive(iface))
		return;

	callbacks_unregister_api_call_result(&iface->base, iface->api_call);
	iface->api_call = 0;
}

/* CCallback */

static void CCallback_Run0(struct CCallbackBase *iface, void *param)
{
	iface->vtbl->Run1(iface, STEAM_FALSE, 0, param);
}

static void CCallback_Run1(struct CCallbackBase *iface, steam_bool_t io_failure, steam_api_call_t api_call, void *param)
{
	struct CCallback *impl = CCallback_from_CCallbackBase(iface);

	(void)io_failure;
	(void)api_call;

	impl->callback(impl->obj, param);
}

static int CCallback_GetCallbackSizeBytes(struct CCallbackBase *iface)
{
	struct CCallback *impl = CCallback_from_CCallbackBase(iface);

	return impl->data_size;
}

static const struct CCallbackBaseVtbl CCallback_vtbl =
{
	.Run0 = CCallback_Run0,
	.Run1 = CCallback_Run1,
	.GetCallbackSizeBytes = CCallback_GetCallbackSizeBytes
};

void CCallback(struct CCallback *iface, void *obj, steam_callback_t callback, size_t data_size, steam_bool_t is_game_server)
{
	CCallbackBase(&iface->base);
	iface->base.vtbl = &CCallback_vtbl;
	iface->obj = obj;
	iface->callback = callback;
	iface->data_size = data_size;

	CCallback_Register(iface, iface->obj, iface->callback);

	if (is_game_server && (iface->base.flags & STEAM_CALLBACK_FLAGS_REGISTERED))
		iface->base.flags |= STEAM_CALLBACK_FLAGS_GAME_SERVER;
}

void CCallback_dtor(struct CCallback *iface)
{
	CCallback_Unregister(iface);
}

void CCallback_Register(struct CCallback *iface, void *obj, steam_callback_t callback)
{
	if (!obj || !callback)
		return;

	if (iface->base.flags & STEAM_CALLBACK_FLAGS_REGISTERED)
		CCallback_Unregister(iface);

	iface->obj = obj;
	iface->callback = callback;

	callbacks_register_callback(&iface->base, iface->base.type);
}

void CCallback_Unregister(struct CCallback *iface)
{
	callbacks_unregister_callback(&iface->base);
}

void CCallback_SetGameserverFlag(struct CCallback *iface)
{
	iface->base.flags |= STEAM_CALLBACK_FLAGS_GAME_SERVER;
}

/* CCallbackManual */

void CCallbackManual(struct CCallbackManual *iface, size_t data_size, steam_bool_t is_game_server)
{
	CCallback(&iface->base, NULL, NULL, data_size, is_game_server);
}

void CCallbackManual_dtor(struct CCallbackManual *iface)
{
	CCallback_dtor(&iface->base);
}
