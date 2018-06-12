#include "macros.h"

#include "ISteamUtils002.h"
#include "ISteamUtils_priv.h"

static const struct ISteamUtils002Vtbl ISteamUtils002_vtbl = {
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
	ISteamUtils_SetOverlayNotificationPosition
};

struct ISteamUtils *SteamUtils002(void)
{
	static struct ISteamUtilsImpl impl;

	impl.base.vtbl.v002 = &ISteamUtils002_vtbl;

	return &impl.base;
}
