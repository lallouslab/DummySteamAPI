#include "macros.h"

#include "ISteamUtils007.h"
#include "ISteamUtils_priv.h"

static const struct ISteamUtils007Vtbl ISteamUtils007_vtbl = {
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
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUtils *SteamUtils007(void)
{
	static struct ISteamUtilsImpl impl;

	impl.base.vtbl.v007 = &ISteamUtils007_vtbl;

	return &impl.base;
}
