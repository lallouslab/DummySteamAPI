#ifndef ISTEAMAPPS_H
#define ISTEAMAPPS_H

#include <stdint.h>

#include "steam.h"

struct ISteamAppsImpl;

struct ISteamApps
{
	steam_bool_t (*BIsSubscribed)(struct ISteamAppsImpl *This);
	steam_bool_t (*BIsLowViolence)(struct ISteamAppsImpl *This);
	steam_bool_t (*BIsCybercafe)(struct ISteamAppsImpl *This);
	steam_bool_t (*BIsVACBanned)(struct ISteamAppsImpl *This);
	const char *(*GetCurrentGameLanguage)(struct ISteamAppsImpl *This);
	const char *(*GetAvailableGameLanguages)(struct ISteamAppsImpl *This);
	steam_bool_t (*BIsSubscribedApp)(struct ISteamAppsImpl *This, steam_app_id_t app_id);
	steam_bool_t (*BIsDlcInstalled)(struct ISteamAppsImpl *This, steam_app_id_t app_id);
};

struct ISteamAppsImpl *SteamApps(void);

#endif /* ISTEAMAPPS */
