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

MEMBER steam_bool_t ISteamApps_BIsCybercafe(struct ISteamApps *iface);
MEMBER steam_bool_t ISteamApps_BIsDlcInstalled(struct ISteamApps *iface, steam_app_id_t app_id);
MEMBER steam_bool_t ISteamApps_BIsLowViolence(struct ISteamApps *iface);
MEMBER steam_bool_t ISteamApps_BIsSubscribed(struct ISteamApps *iface);
MEMBER steam_bool_t ISteamApps_BIsSubscribedApp(struct ISteamApps *iface, steam_app_id_t app_id);
MEMBER steam_bool_t ISteamApps_BIsVACBanned(struct ISteamApps *iface);
MEMBER const char  *ISteamApps_GetAvailableGameLanguages(struct ISteamApps *iface);
MEMBER steam_bool_t ISteamApps_GetCurrentBetaName(struct ISteamApps *iface, char *name, int name_size);
MEMBER const char  *ISteamApps_GetCurrentGameLanguage(struct ISteamApps *iface);
MEMBER int          ISteamApps_GetDLCCount(struct ISteamApps *iface);

#endif /* ISTEAMAPPS_PRIV_H */
