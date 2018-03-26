#ifndef ISTEAMAPPLIST001_H
#define ISTEAMAPPLIST001_H 1

#include "steam.h"

#include "ISteamAppList.h"

#define STEAMAPPLIST_INTERFACE_VERSION_001 "STEAMAPPLIST_INTERFACE_VERSION001"

struct ISteamAppList001Vtbl
{
	void *GetNumInstalledApps;
	void *GetInstalledApps;
	void *GetAppName;
	void *GetAppInstallDir;
	void *GetAppBuildId;
};

struct ISteamAppList *SteamAppList001(void);

#endif /* ISTEAMAPPLIST001_H */
