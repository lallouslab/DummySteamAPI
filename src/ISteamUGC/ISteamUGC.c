#include <string.h>

#include "CCallback.h"
#include "callbacks.h"
#include "debug.h"
#include "steam.h"

#include "ISteamUGC.h"
#include "ISteamUGC_priv.h"
#include "ISteamUGC001.h"
#include "ISteamUGC005.h"
#include "ISteamUGC007.h"
#include "ISteamUGC009.h"
#include "ISteamUGC010.h"

static const char *steam_ugc_version = NULL;

MEMBER steam_ugc_query_handle_t ISteamUGC_CreateQueryUGCDetailsRequest(struct ISteamUGC *iface, steam_published_file_id_t *ids, uint32_t max_ids)
{
	struct ISteamUGCImpl *This = impl_from_ISteamUGC(iface);

	LOG_ENTER_NOTIMPL("(This = %p, ids = %p, max_ids = %u)", VOIDPTR(This), VOIDPTR(ids), max_ids);

	return STEAM_UGC_QUERY_HANDLE_INVAL;
}

MEMBER steam_api_call_t ISteamUGC_SendQueryUGCRequest(struct ISteamUGC *iface, steam_ugc_query_handle_t handle)
{
	struct ISteamUGCImpl *This = impl_from_ISteamUGC(iface);
	struct steam_callback_data_ugc_query_completed ugc_query_completed;

	LOG_ENTER_NOTIMPL("(This = %p, handle = %" PRIu64 ")", VOIDPTR(This), handle);

	ugc_query_completed.handle = handle;
	ugc_query_completed.result = STEAM_RESULT_FAIL;
	ugc_query_completed.returned_count = 0;
	ugc_query_completed.total_count = 0;
	ugc_query_completed.is_data_cached = STEAM_FALSE;

	return callbacks_dispatch_api_call_result_output(STEAM_CALLBACK_TYPE_CLIENT_UGC_QUERY_COMPLETED, STEAM_FALSE, &ugc_query_completed, sizeof(ugc_query_completed));
}

MEMBER steam_bool_t ISteamUGC_ReleaseQueryUGCRequest(struct ISteamUGC *iface, steam_ugc_query_handle_t handle)
{
	struct ISteamUGCImpl *This = impl_from_ISteamUGC(iface);

	LOG_ENTER_NOTIMPL("(This = %p, handle = %" PRIu64 ")", VOIDPTR(This), handle);

	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamUGC_SetReturnChildren(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_children)
{
	struct ISteamUGCImpl *This = impl_from_ISteamUGC(iface);

	LOG_ENTER_NOTIMPL("(This = %p, handle = %" PRIu64 ", return_children = %u)", VOIDPTR(This), handle, return_children);

	return STEAM_FALSE;
}

MEMBER uint32_t ISteamUGC_GetNumSubscribedItems(struct ISteamUGC *iface)
{
	struct ISteamUGCImpl *This = impl_from_ISteamUGC(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

struct ISteamUGC *SteamUGC_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUGC *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUGC_INTERFACE_VERSION_001, SteamUGC001 },
		{ STEAMUGC_INTERFACE_VERSION_005, SteamUGC005 },
		{ STEAMUGC_INTERFACE_VERSION_007, SteamUGC007 },
		{ STEAMUGC_INTERFACE_VERSION_009, SteamUGC009 },
		{ STEAMUGC_INTERFACE_VERSION_010, SteamUGC010 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = \"%s\")", debug_str(version));

	i = 0;
	while (ifaces[i].name)
	{
		if (strcmp(ifaces[i].name, version) == 0)
		{
			if (ifaces[i].iface_getter)
				return ifaces[i].iface_getter();

			break;
		}
		i++;
	}

	WARN("Unable to find ISteamUGC version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamUGC_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_ugc_version)
		steam_ugc_version = version;
}

EXPORT struct ISteamUGC *SteamUGC(void)
{
	static struct ISteamUGC *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_ugc_version)
	{
		steam_ugc_version = STEAMUGC_INTERFACE_VERSION_010;

		WARN("ISteamUGC: No version specified, defaulting to \"%s\".", debug_str(steam_ugc_version));
	}

	if (!cached_iface)
		cached_iface = SteamUGC_generic(steam_ugc_version);

	return cached_iface;
}
