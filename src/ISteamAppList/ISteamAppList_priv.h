#ifndef ISTEAMAPPLIST_PRIV_H
#define ISTEAMAPPLIST_PRIV_H 1

#include "steam.h"

#include "ISteamAppList.h"

struct ISteamAppListImpl
{
	struct ISteamAppList base;
};

static inline struct ISteamAppListImpl *impl_from_ISteamAppList(struct ISteamAppList *iface) {
	return CONTAINER_OF(iface, struct ISteamAppListImpl, base);
}

MEMBER uint32_t ISteamAppList_GetNumInstalledApps(struct ISteamAppList *iface);
MEMBER uint32_t ISteamAppList_GetInstalledApps(struct ISteamAppList *iface, steam_app_id_t *app_ids, uint32_t max_app_ids);
MEMBER int ISteamAppList_GetAppName(struct ISteamAppList *iface, steam_app_id_t app_id, char *name, int max_name_size);
MEMBER int ISteamAppList_GetAppInstallDir(struct ISteamAppList *iface, steam_app_id_t app_id, char *path, int max_path_size);
MEMBER int ISteamAppList_GetAppBuildId(struct ISteamAppList *iface, steam_app_id_t app_id);

#endif /* ISTEAMAPPLIST_PRIV_H */
