#ifndef ISTEAMAPPS_H
#define ISTEAMAPPS_H

#include <stdint.h>

#include "steam.h"

struct ISteamAppsImpl;

struct ISteamApps
{
	int (*BIsSubscribed)(struct ISteamAppsImpl *This);
	int (*BIsLowViolence)(struct ISteamAppsImpl *This);
	int (*BIsCybercafe)(struct ISteamAppsImpl *This);
	int (*BIsVACBanned)(struct ISteamAppsImpl *This);
	const char *(*GetCurrentGameLanguage)(struct ISteamAppsImpl *This);
	const char *(*GetAvailableGameLanguages)(struct ISteamAppsImpl *This);
	int (*BIsSubscribedApp)(struct ISteamAppsImpl *This, steam_app_id_t app_id);
	int (*BIsDlcInstalled)(struct ISteamAppsImpl *This, steam_app_id_t app_id);
};

struct ISteamAppsImpl *SteamApps(void);

#endif /* ISTEAMAPPS */
