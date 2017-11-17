#include "isteamapps.h"
#include "utils.h"

struct ISteamAppsImpl
{
	const struct ISteamApps *iface;
};

static steam_bool_t ISteamApps_BIsSubscribed(struct ISteamAppsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

static steam_bool_t ISteamApps_BIsLowViolence(struct ISteamAppsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

static steam_bool_t ISteamApps_BIsCybercafe(struct ISteamAppsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

static steam_bool_t ISteamApps_BIsVACBanned(struct ISteamAppsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
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

static steam_bool_t ISteamApps_BIsSubscribedApp(struct ISteamAppsImpl *This, steam_app_id_t app_id)
{
	log_enter_notimpl("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return STEAM_TRUE;
}

static steam_bool_t ISteamApps_BIsDlcInstalled(struct ISteamAppsImpl *This, steam_app_id_t app_id)
{
	log_enter_notimpl("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return STEAM_FALSE;
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
