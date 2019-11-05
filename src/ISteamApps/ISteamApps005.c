#include "macros.h"

#include "ISteamApps005.h"
#include "ISteamApps_priv.h"

static const struct ISteamApps005Vtbl ISteamApps005_vtbl = {
	ISteamApps_BIsSubscribed,
	ISteamApps_BIsLowViolence,
	ISteamApps_BIsCybercafe,
	ISteamApps_BIsVACBanned,
	ISteamApps_GetCurrentGameLanguage,
	ISteamApps_GetAvailableGameLanguages,
	ISteamApps_BIsSubscribedApp,
	ISteamApps_BIsDlcInstalled,
	INVAL_PTR,
	INVAL_PTR,
	ISteamApps_GetDLCCount,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamApps_GetCurrentBetaName,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamApps *SteamApps005(void)
{
	static struct ISteamAppsImpl impl;

	impl.base.vtbl.v005 = &ISteamApps005_vtbl;

	return &impl.base;
}
