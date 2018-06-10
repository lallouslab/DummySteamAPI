#include "macros.h"

#include "ISteamParentalSettings001.h"
#include "ISteamParentalSettings_priv.h"

static const struct ISteamParentalSettings001Vtbl ISteamParentalSettings001_vtbl = {
	ISteamParentalSettings_BIsParentalLockEnabled,
	ISteamParentalSettings_BIsParentalLockLocked,
	ISteamParentalSettings_BIsAppBlocked,
	ISteamParentalSettings_BIsAppInBlockList,
	ISteamParentalSettings_BIsFeatureBlocked,
	ISteamParentalSettings_BIsFeatureInBlockList
};

struct ISteamParentalSettings *SteamParentalSettings001(void)
{
	static struct ISteamParentalSettingsImpl impl;

	impl.base.vtbl.v001 = &ISteamParentalSettings001_vtbl;

	return &impl.base;
}
