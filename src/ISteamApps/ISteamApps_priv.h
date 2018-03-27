#ifndef ISTEAMAPPS_PRIV_H
#define ISTEAMAPPS_PRIV_H 1

#include "steam.h"

#include "ISteamApps.h"

struct ISteamAppsImpl
{
	struct ISteamApps base;
};

static inline struct ISteamAppsImpl *impl_from_ISteamApps(struct ISteamApps *iface) {
	return CONTAINER_OF(iface, struct ISteamAppsImpl, base);
}

steam_bool_t ISteamApps_BIsCybercafe(struct ISteamApps *iface);
steam_bool_t ISteamApps_BIsDlcInstalled(struct ISteamApps *iface, steam_app_id_t app_id);
steam_bool_t ISteamApps_BIsLowViolence(struct ISteamApps *iface);
steam_bool_t ISteamApps_BIsSubscribed(struct ISteamApps *iface);
steam_bool_t ISteamApps_BIsSubscribedApp(struct ISteamApps *iface, steam_app_id_t app_id);
steam_bool_t ISteamApps_BIsVACBanned(struct ISteamApps *iface);
const char *ISteamApps_GetAvailableGameLanguages(struct ISteamApps *iface);
const char *ISteamApps_GetCurrentGameLanguage(struct ISteamApps *iface);

#endif /* ISTEAMAPPS_PRIV_H */
