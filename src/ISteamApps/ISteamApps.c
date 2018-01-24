#include <string.h>

#include "utils.h"

#include "ISteamApps.h"
#include "ISteamApps_priv.h"
#include "ISteamApps001.h"
#include "ISteamApps003.h"
#include "ISteamApps006.h"

steam_bool_t ISteamApps_BIsCybercafe(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

steam_bool_t ISteamApps_BIsDlcInstalled(struct ISteamApps *iface, steam_app_id_t app_id)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return STEAM_TRUE;
}

steam_bool_t ISteamApps_BIsLowViolence(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

steam_bool_t ISteamApps_BIsSubscribed(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

steam_bool_t ISteamApps_BIsSubscribedApp(struct ISteamApps *iface, steam_app_id_t app_id)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return STEAM_TRUE;
}

steam_bool_t ISteamApps_BIsVACBanned(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

const char *ISteamApps_GetAvailableGameLanguages(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return "french,english";
}

const char *ISteamApps_GetCurrentGameLanguage(struct ISteamApps *iface)
{
	struct ISteamAppsImpl *This = impl_from_ISteamApps(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return "french";
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
		{ STEAMAPPS_INTERFACE_VERSION_006, SteamApps006 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = %s)", version);

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

	WARN("Unable to find ISteamApps version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamApps *SteamApps(void)
{
	LOG_ENTER0("()");

	return SteamApps006();
}
