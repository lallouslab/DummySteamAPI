#include "utils.h"

#include "ISteamUtils001.h"
#include "ISteamUtils_priv.h"

static const struct ISteamUtils001 ISteamUtils001_vtbl = {
	ISteamUtils_GetSecondsSinceAppActive,
	INVAL_PTR,
	ISteamUtils_GetConnectedUniverse,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUtilsImpl *SteamUtils001(void)
{
	static struct ISteamUtilsImpl impl;

	impl.iface = &ISteamUtils001_vtbl;

	return &impl;
}
