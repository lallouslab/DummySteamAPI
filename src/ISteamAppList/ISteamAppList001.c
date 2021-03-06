#include "macros.h"

#include "ISteamAppList001.h"
#include "ISteamAppList_priv.h"

static const struct ISteamAppList001Vtbl ISteamAppList001_vtbl = {
	ISteamAppList_GetNumInstalledApps,
	ISteamAppList_GetInstalledApps,
	ISteamAppList_GetAppName,
	ISteamAppList_GetAppInstallDir,
	ISteamAppList_GetAppBuildId
};

struct ISteamAppList *SteamAppList001(void)
{
	static struct ISteamAppListImpl impl;

	impl.base.vtbl.v001 = &ISteamAppList001_vtbl;

	return &impl.base;
}
