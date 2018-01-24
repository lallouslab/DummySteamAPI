#include "utils.h"

#include "ISteamUtils006.h"
#include "ISteamUtils_priv.h"

static const struct ISteamUtils006 ISteamUtils006_vtbl = {
	ISteamUtils_GetSecondsSinceAppActive,
	INVAL_PTR,
	ISteamUtils_GetConnectedUniverse,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUtils_GetAppID,
	ISteamUtils_SetOverlayNotificationPosition,
	ISteamUtils_IsAPICallCompleted,
	INVAL_PTR,
	ISteamUtils_GetAPICallResult,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUtils_SetWarningMessageHook,
	ISteamUtils_IsOverlayEnabled,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUtils_GetSteamUILanguage,
	INVAL_PTR
};

struct ISteamUtilsImpl *SteamUtils006(void)
{
	static struct ISteamUtilsImpl impl;

	impl.iface = &ISteamUtils006_vtbl;

	return &impl;
}
