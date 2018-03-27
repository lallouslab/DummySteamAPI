#ifndef ISTEAMAPPS003_H
#define ISTEAMAPPS003_H 1

#include "steam.h"

#include "ISteamApps.h"

#define STEAMAPPS_INTERFACE_VERSION_003 "STEAMAPPS_INTERFACE_VERSION003"

struct ISteamApps003Vtbl
{
	MEMBER steam_bool_t (*BIsSubscribed)(struct ISteamApps *iface);
	MEMBER steam_bool_t (*BIsLowViolence)(struct ISteamApps *iface);
	MEMBER steam_bool_t (*BIsCybercafe)(struct ISteamApps *iface);
	MEMBER steam_bool_t (*BIsVACBanned)(struct ISteamApps *iface);
	MEMBER const char *(*GetCurrentGameLanguage)(struct ISteamApps *iface);
	MEMBER const char *(*GetAvailableGameLanguages)(struct ISteamApps *iface);
	MEMBER steam_bool_t (*BIsSubscribedApp)(struct ISteamApps *iface, steam_app_id_t app_id);
	MEMBER steam_bool_t (*BIsDlcInstalled)(struct ISteamApps *iface, steam_app_id_t app_id);
};

struct ISteamApps *SteamApps003(void);

#endif /* ISTEAMAPPS003_H */
