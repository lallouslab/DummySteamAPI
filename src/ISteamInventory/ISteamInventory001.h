#ifndef ISTEAMINVENTORY001_H
#define ISTEAMINVENTORY001_H 1

#include "steam.h"

#include "ISteamInventory.h"

#define STEAMINVENTORY_INTERFACE_VERSION_001 "STEAMINVENTORY_INTERFACE_V001"

struct ISteamInventory001Vtbl
{
	void *GetNumInstalledApps;
	void *GetInstalledApps;
	void *GetAppName;
	void *GetAppInstallDir;
	void *GetAppBuildId;
};

struct ISteamInventory *SteamInventory001(void);

#endif /* ISTEAMINVENTORY001_H */
