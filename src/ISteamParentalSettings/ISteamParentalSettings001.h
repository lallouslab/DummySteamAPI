#ifndef ISTEAMPARENTALSETTINGS001_H
#define ISTEAMPARENTALSETTINGS001_H 1

#include "steam.h"

#include "ISteamParentalSettings.h"

#define STEAMPARENTALSETTINGS_INTERFACE_VERSION_001 "STEAMPARENTALSETTINGS_INTERFACE_VERSION001"

struct ISteamParentalSettings001Vtbl
{
	MEMBER steam_bool_t (*BIsParentalLockEnabled)(struct ISteamParentalSettings *iface);
	MEMBER steam_bool_t (*BIsParentalLockLocked)(struct ISteamParentalSettings *iface);
	MEMBER steam_bool_t (*BIsAppBlocked)(struct ISteamParentalSettings *iface, steam_app_id_t app_id);
	MEMBER steam_bool_t (*BIsAppInBlockList)(struct ISteamParentalSettings *iface, steam_app_id_t app_id);
	MEMBER steam_bool_t (*BIsFeatureBlocked)(struct ISteamParentalSettings *iface, enum steam_parental_settings_feature feature);
	MEMBER steam_bool_t (*BIsFeatureInBlockList)(struct ISteamParentalSettings *iface, enum steam_parental_settings_feature feature);
};

struct ISteamParentalSettings *SteamParentalSettings001(void);

#endif /* ISTEAMPARENTALSETTINGS001_H */
