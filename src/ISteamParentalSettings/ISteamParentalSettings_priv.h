#ifndef ISTEAMPARENTALSETTINGS_PRIV_H
#define ISTEAMPARENTALSETTINGS_PRIV_H 1

#include "steam.h"

#include "ISteamParentalSettings.h"

struct ISteamParentalSettingsImpl
{
	struct ISteamParentalSettings base;
};

static inline struct ISteamParentalSettingsImpl *impl_from_ISteamParentalSettings(struct ISteamParentalSettings *iface) {
	return CONTAINER_OF(iface, struct ISteamParentalSettingsImpl, base);
}

MEMBER steam_bool_t ISteamParentalSettings_BIsParentalLockEnabled(struct ISteamParentalSettings *iface);
MEMBER steam_bool_t ISteamParentalSettings_BIsParentalLockLocked(struct ISteamParentalSettings *iface);
MEMBER steam_bool_t ISteamParentalSettings_BIsAppBlocked(struct ISteamParentalSettings *iface, steam_app_id_t app_id);
MEMBER steam_bool_t ISteamParentalSettings_BIsAppInBlockList(struct ISteamParentalSettings *iface, steam_app_id_t app_id);
MEMBER steam_bool_t ISteamParentalSettings_BIsFeatureBlocked(struct ISteamParentalSettings *iface, enum steam_parental_settings_feature feature);
MEMBER steam_bool_t ISteamParentalSettings_BIsFeatureInBlockList(struct ISteamParentalSettings *iface, enum steam_parental_settings_feature feature);

#endif /* ISTEAMPARENTALSETTINGS_PRIV_H */
