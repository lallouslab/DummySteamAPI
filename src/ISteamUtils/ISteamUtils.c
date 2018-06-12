#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "CCallback.h"
#include "callbacks.h"
#include "config.h"
#include "debug.h"
#include "steam.h"
#include "utils.h"

#include "ISteamUtils.h"
#include "ISteamUtils_priv.h"
#include "ISteamUtils001.h"
#include "ISteamUtils002.h"
#include "ISteamUtils006.h"
#include "ISteamUtils007.h"
#include "ISteamUtils009.h"

static const char *steam_utils_version = NULL;

MEMBER uint32_t ISteamUtils_GetSecondsSinceAppActive(struct ISteamUtils *iface)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

MEMBER enum steam_universe ISteamUtils_GetConnectedUniverse(struct ISteamUtils *iface)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_UNIVERSE_PUBLIC;
}

MEMBER uint32_t ISteamUtils_GetServerRealTime(struct ISteamUtils *iface)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER("(This = %p)", VOIDPTR(This));

	return time(NULL);
}

MEMBER const char *ISteamUtils_GetIPCountry(struct ISteamUtils *iface)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER("(This = %p)", VOIDPTR(This));

	return "FR";
}

MEMBER steam_bool_t ISteamUtils_GetImageSize(struct ISteamUtils *iface, int handle, uint32_t *w, uint32_t *h)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER("(This = %p, handle = %d, w = %p, h = %p)", VOIDPTR(This), handle, VOIDPTR(w), VOIDPTR(h));

	*w = 0;
	*h = 0;

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUtils_GetImageRGBA(struct ISteamUtils *iface, int handle, uint8_t *buf, int buf_size)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER("(This = %p, handle = %d, buf = %p, buf_size = %d)", VOIDPTR(This), handle, VOIDPTR(buf), buf_size);

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUtils_GetCSERIPPort(struct ISteamUtils *iface, uint32_t *ip, uint16_t *port)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER_NOTIMPL("(This = %p, ip = %p, port = %p)", VOIDPTR(This), VOIDPTR(ip), VOIDPTR(port));

	*ip = 0;
	*port = 0;

	return STEAM_TRUE;
}

MEMBER steam_app_id_t ISteamUtils_GetAppID(struct ISteamUtils *iface)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER("(This = %p)", VOIDPTR(This));

	return dsa_config_get_steam_app_id();
}

MEMBER void ISteamUtils_SetOverlayNotificationPosition(struct ISteamUtils *iface, enum steam_notification_position pos)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER_NOTIMPL("(This = %p, pos = %u)", VOIDPTR(This), pos);
}

MEMBER steam_bool_t ISteamUtils_IsAPICallCompleted(struct ISteamUtils *iface, steam_api_call_t api_call, steam_bool_t *failed)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER("(This = %p, api_call = %" PRIu64 ", failed = %p)", VOIDPTR(This), api_call, VOIDPTR(failed));

	return callbacks_api_call_result_is_output_available(api_call, failed);
}

MEMBER steam_bool_t ISteamUtils_GetAPICallResult(struct ISteamUtils *iface, steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *failed)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER("(This = %p, api_call = %" PRIu64 ", data = %p, data_size = %d, type_expected = %s (%u), failed = %p)", VOIDPTR(This), api_call, data, data_size, dsa_debug_steam_callback_type(type_expected), type_expected, VOIDPTR(failed));

	return callbacks_api_call_result_get_output(api_call, data, data_size, type_expected, failed);
}

MEMBER void ISteamUtils_SetWarningMessageHook(struct ISteamUtils *iface, void *callback)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER_NOTIMPL("(This = %p, callback = %p)", VOIDPTR(This), VOIDPTR(callback));
}

MEMBER steam_bool_t ISteamUtils_IsOverlayEnabled(struct ISteamUtils *iface)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

MEMBER const char *ISteamUtils_GetSteamUILanguage(struct ISteamUtils *iface)
{
	struct ISteamUtilsImpl *This = impl_from_ISteamUtils(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return "french";
}

struct ISteamUtils *SteamUtils_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUtils *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUTILS_INTERFACE_VERSION_001, SteamUtils001 },
		{ STEAMUTILS_INTERFACE_VERSION_002, SteamUtils002 },
		{ STEAMUTILS_INTERFACE_VERSION_006, SteamUtils006 },
		{ STEAMUTILS_INTERFACE_VERSION_007, SteamUtils007 },
		{ STEAMUTILS_INTERFACE_VERSION_009, SteamUtils009 },
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

	WARN("Unable to find ISteamUtils version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamUtils_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_utils_version)
		steam_utils_version = version;
}

EXPORT struct ISteamUtils *SteamUtils(void)
{
	static struct ISteamUtils *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_utils_version)
	{
		steam_utils_version = STEAMUTILS_INTERFACE_VERSION_009;

		WARN("ISteamUtils: No version specified, defaulting to \"%s\".", debug_str(steam_utils_version));
	}

	if (!cached_iface)
		cached_iface = SteamUtils_generic(steam_utils_version);

	return cached_iface;
}
