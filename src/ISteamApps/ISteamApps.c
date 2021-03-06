#include <string.h>

#include "debug.h"
#include "steam.h"

#include "ISteamApps.h"
#include "ISteamApps_priv.h"
#include "ISteamApps001.h"
#include "ISteamApps003.h"
#include "ISteamApps005.h"
#include "ISteamApps006.h"
#include "ISteamApps007.h"
#include "ISteamApps008.h"

static const char *steam_apps_version = NULL;

MEMBER steam_bool_t ISteamApps_BIsCybercafe(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamApps_BIsDlcInstalled(struct ISteamApps *iface, steam_app_id_t app_id)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamApps_BIsLowViolence(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamApps_BIsSubscribed(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamApps_BIsSubscribedApp(struct ISteamApps *iface, steam_app_id_t app_id)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return STEAM_TRUE;
}

EXPORT steam_bool_t SteamAPI_ISteamApps_BIsSubscribedApp(struct ISteamApps *iface, steam_app_id_t app_id)
{
	return ISteamApps_BIsSubscribedApp(iface, app_id);
}

MEMBER steam_bool_t ISteamApps_BIsVACBanned(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

MEMBER const char *ISteamApps_GetAvailableGameLanguages(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return "french,english";
}

MEMBER steam_bool_t ISteamApps_GetCurrentBetaName(struct ISteamApps *iface, char *name, int name_size)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = %p, name_size = %d)", VOIDPTR(This), VOIDPTR(name), name_size);

	return STEAM_FALSE;
}

MEMBER const char *ISteamApps_GetCurrentGameLanguage(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return "french";
}

EXPORT const char *SteamAPI_ISteamApps_GetCurrentGameLanguage(struct ISteamApps *iface)
{
	return ISteamApps_GetCurrentGameLanguage(iface);
}

MEMBER int ISteamApps_GetDLCCount(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

struct ISteamApps *SteamApps_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamApps *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMAPPS_INTERFACE_VERSION_001, SteamApps001 },
		{ STEAMAPPS_INTERFACE_VERSION_003, SteamApps003 },
		{ STEAMAPPS_INTERFACE_VERSION_005, SteamApps005 },
		{ STEAMAPPS_INTERFACE_VERSION_006, SteamApps006 },
		{ STEAMAPPS_INTERFACE_VERSION_007, SteamApps007 },
		{ STEAMAPPS_INTERFACE_VERSION_008, SteamApps008 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = \"%s\")", debug_str(version));

	i = 0;
	while (ifaces[i].name)
	{
		if (strcmp(ifaces[i].name, version) == 0)
		{
			if (ifaces[i].iface_getter)
				return ifaces[i].iface_getter();

			break;
		}
		i++;
	}

	WARN("Unable to find ISteamApps version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamApps_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_apps_version)
		steam_apps_version = version;
}

EXPORT struct ISteamApps *SteamApps(void)
{
	static struct ISteamApps *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_apps_version)
	{
		steam_apps_version = STEAMAPPS_INTERFACE_VERSION_008;

		WARN("ISteamApps: No version specified, defaulting to \"%s\".", debug_str(steam_apps_version));
	}

	if (!cached_iface)
		cached_iface = SteamApps_generic(steam_apps_version);

	return cached_iface;
}
