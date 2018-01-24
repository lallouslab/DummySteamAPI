#include "utils.h"

#include "ISteamApps001.h"
#include "ISteamApps_priv.h"

static const struct ISteamApps001 ISteamApps001_vtbl = {
	INVAL_PTR
};

struct ISteamApps *SteamApps001(void)
{
	static struct ISteamAppsImpl impl;

	impl.base.iface = &ISteamApps001_vtbl;

	return &impl.base;
}
