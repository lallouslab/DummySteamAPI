#ifndef ISTEAMAPPS003_H
#define ISTEAMAPPS003_H 1

#include "steam.h"

#include "ISteamApps.h"

#define STEAMAPPS_INTERFACE_VERSION_003 "STEAMAPPS_INTERFACE_VERSION003"

struct ISteamApps003Vtbl
{
	steam_bool_t (*BIsSubscribed)(struct ISteamApps *iface);
	steam_bool_t (*BIsLowViolence)(struct ISteamApps *iface);
	steam_bool_t (*BIsCybercafe)(struct ISteamApps *iface);
	steam_bool_t (*BIsVACBanned)(struct ISteamApps *iface);
	const char *(*GetCurrentGameLanguage)(struct ISteamApps *iface);
	const char *(*GetAvailableGameLanguages)(struct ISteamApps *iface);
	steam_bool_t (*BIsSubscribedApp)(struct ISteamApps *iface, steam_app_id_t app_id);
	steam_bool_t (*BIsDlcInstalled)(struct ISteamApps *iface, steam_app_id_t app_id);
};

static inline struct ISteamApps003Vtbl *get_ISteamApps003Vtbl_from_ISteamApps(struct ISteamApps *iface) {
	return (struct ISteamApps003Vtbl *)iface->vtbl;
}

struct ISteamApps *SteamApps003(void);

#endif /* ISTEAMAPPS003_H */
