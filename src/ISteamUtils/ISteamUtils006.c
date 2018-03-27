#include "macros.h"

#include "ISteamUtils006.h"
#include "ISteamUtils_priv.h"

static const struct ISteamUtils006Vtbl ISteamUtils006_vtbl = {
	ISteamUtils_GetSecondsSinceAppActive,
	INVAL_PTR,
	ISteamUtils_GetConnectedUniverse,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUtils_GetCSERIPPort,
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

struct ISteamUtils *SteamUtils006(void)
{
	static struct ISteamUtilsImpl impl;

	impl.base.vtbl.v006 = &ISteamUtils006_vtbl;

	return &impl.base;
}
