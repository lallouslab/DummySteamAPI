#include "utils.h"

#include "ISteamApps001.h"
#include "ISteamApps_priv.h"

static const struct ISteamApps001Vtbl ISteamApps001_vtbl = {
	INVAL_PTR
};

struct ISteamApps *SteamApps001(void)
{
	static struct ISteamAppsImpl impl;

	impl.base.vtbl = &ISteamApps001_vtbl;

	return &impl.base;
}
