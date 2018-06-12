#include "macros.h"

#include "ISteamUtils001.h"
#include "ISteamUtils_priv.h"

static const struct ISteamUtils001Vtbl ISteamUtils001_vtbl = {
	ISteamUtils_GetSecondsSinceAppActive,
	INVAL_PTR,
	ISteamUtils_GetConnectedUniverse,
	ISteamUtils_GetServerRealTime,
	ISteamUtils_GetIPCountry,
	INVAL_PTR,
	ISteamUtils_GetImageRGBA
};

struct ISteamUtils *SteamUtils001(void)
{
	static struct ISteamUtilsImpl impl;

	impl.base.vtbl.v001 = &ISteamUtils001_vtbl;

	return &impl.base;
}
