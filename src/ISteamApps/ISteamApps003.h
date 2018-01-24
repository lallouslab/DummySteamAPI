#ifndef ISTEAMAPPS003_H
#define ISTEAMAPPS003_H 1

#include "steam.h"

#include "ISteamApps.h"

#define STEAMAPPS_INTERFACE_VERSION_003 "STEAMAPPS_INTERFACE_VERSION003"

struct ISteamApps003
{
	steam_bool_t (*BIsSubscribed)(struct ISteamApps *This);
	steam_bool_t (*BIsLowViolence)(struct ISteamApps *This);
	steam_bool_t (*BIsCybercafe)(struct ISteamApps *This);
	steam_bool_t (*BIsVACBanned)(struct ISteamApps *This);
	const char *(*GetCurrentGameLanguage)(struct ISteamApps *This);
	const char *(*GetAvailableGameLanguages)(struct ISteamApps *This);
	steam_bool_t (*BIsSubscribedApp)(struct ISteamApps *This, steam_app_id_t app_id);
	steam_bool_t (*BIsDlcInstalled)(struct ISteamApps *This, steam_app_id_t app_id);
};

static inline struct ISteamApps003 *get_ISteamApps003_from_ISteamApps(struct ISteamApps *iface) {
	return (struct ISteamApps003 *)iface->iface;
}

struct ISteamApps *SteamApps003(void);

#endif /* ISTEAMAPPS003_H */
