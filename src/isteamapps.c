#include "isteamapps.h"
#include "utils.h"

struct ISteamAppsImpl
{
	const struct ISteamApps *iface;
};

static int ISteamApps_BIsSubscribed(struct ISteamAppsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return 1;
}

static int ISteamApps_BIsLowViolence(struct ISteamAppsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return 1;
}

static int ISteamApps_BIsCybercafe(struct ISteamAppsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return 0;
}

static int ISteamApps_BIsVACBanned(struct ISteamAppsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return 0;
}

static const char *ISteamApps_GetCurrentGameLanguage(struct ISteamAppsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return "french";
}

static const char *ISteamApps_GetAvailableGameLanguages(struct ISteamAppsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return "french,english";
}

static int ISteamApps_BIsSubscribedApp(struct ISteamAppsImpl *This, uint32_t app_id)
{
	log_enter_notimpl("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return 1;
}

static int ISteamApps_BIsDlcInstalled(struct ISteamAppsImpl *This, uint32_t app_id)
{
	log_enter_notimpl("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return 0;
}

static const struct ISteamApps ISteamApps_vtbl = {
	ISteamApps_BIsSubscribed,
	ISteamApps_BIsLowViolence,
	ISteamApps_BIsCybercafe,
	ISteamApps_BIsVACBanned,
	ISteamApps_GetCurrentGameLanguage,
	ISteamApps_GetAvailableGameLanguages,
	ISteamApps_BIsSubscribedApp,
	ISteamApps_BIsDlcInstalled
};

struct ISteamAppsImpl *SteamApps(void)
{
	static struct ISteamAppsImpl impl;

	impl.iface = &ISteamApps_vtbl;

	return &impl;
}
