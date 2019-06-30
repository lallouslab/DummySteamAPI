#include "macros.h"

#include "ISteamApps008.h"
#include "ISteamApps_priv.h"

static const struct ISteamApps008Vtbl ISteamApps008_vtbl = {
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
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamApps *SteamApps008(void)
{
	static struct ISteamAppsImpl impl;

	impl.base.vtbl.v008 = &ISteamApps008_vtbl;

	return &impl.base;
}
