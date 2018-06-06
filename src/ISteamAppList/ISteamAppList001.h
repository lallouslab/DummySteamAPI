#ifndef ISTEAMAPPLIST001_H
#define ISTEAMAPPLIST001_H 1

#include "steam.h"

#include "ISteamAppList.h"

#define STEAMAPPLIST_INTERFACE_VERSION_001 "STEAMAPPLIST_INTERFACE_VERSION001"

struct ISteamAppList001Vtbl
{
	MEMBER uint32_t (*GetNumInstalledApps)(struct ISteamAppList *iface);
	MEMBER uint32_t (*GetInstalledApps)(struct ISteamAppList *iface, steam_app_id_t *app_ids, uint32_t max_app_ids);
	MEMBER int (*GetAppName)(struct ISteamAppList *iface, steam_app_id_t app_id, char *name, int max_name_size);
	MEMBER int (*GetAppInstallDir)(struct ISteamAppList *iface, steam_app_id_t app_id, char *path, int max_path_size);
	MEMBER int (*GetAppBuildId)(struct ISteamAppList *iface, steam_app_id_t app_id);
};

struct ISteamAppList *SteamAppList001(void);

#endif /* ISTEAMAPPLIST001_H */
