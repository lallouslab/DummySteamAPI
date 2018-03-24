#include <string.h>

#include "debug.h"
#include "utils.h"

#include "ISteamAppList.h"
#include "ISteamAppList_priv.h"
#include "ISteamAppList001.h"

static const char *steam_app_list_version = NULL;

struct ISteamAppList *SteamAppList_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamAppList *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMAPPLIST_INTERFACE_VERSION_001, SteamAppList001 },
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

	WARN("Unable to find ISteamAppList version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamAppList_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_app_list_version)
		steam_app_list_version = version;
}

EXPORT struct ISteamAppList *SteamAppList(void)
{
	static struct ISteamAppList *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_app_list_version)
	{
		steam_app_list_version = STEAMAPPLIST_INTERFACE_VERSION_001;

		WARN("ISteamAppList: No version specified, defaulting to \"%s\".", debug_str(steam_app_list_version));
	}

	if (!cached_iface)
		cached_iface = SteamAppList_generic(steam_app_list_version);

	return cached_iface;
}
