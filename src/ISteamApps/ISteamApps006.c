#include "macros.h"

#include "ISteamApps006.h"
#include "ISteamApps_priv.h"

static const struct ISteamApps006Vtbl ISteamApps006_vtbl = {
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
	INVAL_PTR
};

struct ISteamApps *SteamApps006(void)
{
	static struct ISteamAppsImpl impl;

	impl.base.vtbl.v006 = &ISteamApps006_vtbl;

	return &impl.base;
}
