#include "ISteamApps003.h"
#include "ISteamApps_priv.h"

static const struct ISteamApps003Vtbl ISteamApps003_vtbl = {
	ISteamApps_BIsSubscribed,
	ISteamApps_BIsLowViolence,
	ISteamApps_BIsCybercafe,
	ISteamApps_BIsVACBanned,
	ISteamApps_GetCurrentGameLanguage,
	ISteamApps_GetAvailableGameLanguages,
	ISteamApps_BIsSubscribedApp,
	ISteamApps_BIsDlcInstalled
};

struct ISteamApps *SteamApps003(void)
{
	static struct ISteamAppsImpl impl;

	impl.base.vtbl.v003 = &ISteamApps003_vtbl;

	return &impl.base;
}
