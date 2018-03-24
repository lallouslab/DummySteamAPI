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

static inline struct ISteamAppList001Vtbl *get_ISteamAppList001Vtbl_from_ISteamAppList(struct ISteamAppList *iface) {
	return (struct ISteamAppList001Vtbl *)iface->vtbl;
}

struct ISteamAppList *SteamAppList001(void);

#endif /* ISTEAMAPPLIST001_H */
