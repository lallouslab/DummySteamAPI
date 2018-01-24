#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#include "callbacks.h"
#include "utils.h"

#include "ISteamUtils.h"
#include "ISteamUtils_priv.h"
#include "ISteamUtils001.h"
#include "ISteamUtils006.h"

uint32_t ISteamUtils_GetSecondsSinceAppActive(struct ISteamUtilsImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

enum steam_universe ISteamUtils_GetConnectedUniverse(struct ISteamUtilsImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_UNIVERSE_PUBLIC;
}

steam_app_id_t ISteamUtils_GetAppID(struct ISteamUtilsImpl *This)
{
	const char *app_id;

	LOG_ENTER("(This = %p)", VOIDPTR(This));

	app_id = getenv("SteamAppId");
	if (!app_id)
	{
		WARN0("SteamAppId is not set.");
		app_id = "1";
	}

	return strtoul(app_id, NULL, 0);
}

void ISteamUtils_SetOverlayNotificationPosition(struct ISteamUtilsImpl *This, enum steam_notification_position pos)
{
	LOG_ENTER_NOTIMPL("(This = %p, pos = %u)", VOIDPTR(This), pos);
}

steam_bool_t ISteamUtils_IsAPICallCompleted(struct ISteamUtilsImpl *This, steam_api_call_t api_call, steam_bool_t *failed)
{
	LOG_ENTER("(This = %p, api_call = %" PRIu64 ", failed = %p)", VOIDPTR(This), api_call, VOIDPTR(failed));

	return callbacks_api_call_result_output_available(api_call, failed);
}

steam_bool_t ISteamUtils_GetAPICallResult(struct ISteamUtilsImpl *This, steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *failed)
{
	LOG_ENTER("(This = %p, api_call = %" PRIu64 ", data = %p, data_size = %d, type_expected = %d, failed = %p)", VOIDPTR(This), api_call, data, data_size, type_expected, VOIDPTR(failed));

	return callbacks_api_call_result_get_output(STEAM_FALSE, api_call, data, data_size, type_expected, failed);
}

void ISteamUtils_SetWarningMessageHook(struct ISteamUtilsImpl *This, void *callback)
{
	LOG_ENTER_NOTIMPL("(This = %p, callback = %p)", VOIDPTR(This), VOIDPTR(callback));
}

steam_bool_t ISteamUtils_IsOverlayEnabled(struct ISteamUtilsImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

const char *ISteamUtils_GetSteamUILanguage(struct ISteamUtilsImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return "french";
}

struct ISteamUtilsImpl *SteamUtils_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUtilsImpl *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUTILS_INTERFACE_VERSION_001, SteamUtils001 },
		{ STEAMUTILS_INTERFACE_VERSION_006, SteamUtils006 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = %s)", version);

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

	WARN("Unable to find ISteamUtils version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamUtilsImpl *SteamUtils(void)
{
	LOG_ENTER0("()");

	return SteamUtils006();
}
