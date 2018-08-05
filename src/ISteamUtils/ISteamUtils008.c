#include "macros.h"

#include "ISteamUtils008.h"
#include "ISteamUtils_priv.h"

static const struct ISteamUtils008Vtbl ISteamUtils008_vtbl = {
	ISteamUtils_GetSecondsSinceAppActive,
	INVAL_PTR,
	ISteamUtils_GetConnectedUniverse,
	ISteamUtils_GetServerRealTime,
	ISteamUtils_GetIPCountry,
	ISteamUtils_GetImageSize,
	ISteamUtils_GetImageRGBA,
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
	INVAL_PTR
};

struct ISteamUtils *SteamUtils008(void)
{
	static struct ISteamUtilsImpl impl;

	impl.base.vtbl.v008 = &ISteamUtils008_vtbl;

	return &impl.base;
}
