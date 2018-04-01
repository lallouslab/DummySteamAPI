#include "macros.h"

#include "ISteamUtils009.h"
#include "ISteamUtils_priv.h"

static const struct ISteamUtils009Vtbl ISteamUtils009_vtbl = {
	ISteamUtils_GetSecondsSinceAppActive,
	INVAL_PTR,
	ISteamUtils_GetConnectedUniverse,
	ISteamUtils_GetServerRealTime,
	ISteamUtils_GetIPCountry,
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
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUtils *SteamUtils009(void)
{
	static struct ISteamUtilsImpl impl;

	impl.base.vtbl.v009 = &ISteamUtils009_vtbl;

	return &impl.base;
}
