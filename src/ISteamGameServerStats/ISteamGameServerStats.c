#include <string.h>

#include "debug.h"
#include "steam.h"

#include "ISteamGameServerStats.h"
#include "ISteamGameServerStats_priv.h"
#include "ISteamGameServerStats001.h"

static const char *steam_game_server_stats_version = NULL;

struct ISteamGameServerStats *SteamGameServerStats_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamGameServerStats *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMGAMESERVERSTATS_INTERFACE_VERSION_001, SteamGameServerStats001 },
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

	WARN("Unable to find ISteamGameServerStats version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamGameServerStats_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_game_server_stats_version)
		steam_game_server_stats_version = version;
}

EXPORT struct ISteamGameServerStats *SteamGameServerStats(void)
{
	static struct ISteamGameServerStats *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_game_server_stats_version)
	{
		steam_game_server_stats_version = STEAMGAMESERVERSTATS_INTERFACE_VERSION_001;

		WARN("ISteamGameServerStats: No version specified, defaulting to \"%s\".", debug_str(steam_game_server_stats_version));
	}

	if (!cached_iface)
		cached_iface = SteamGameServerStats_generic(steam_game_server_stats_version);

	return cached_iface;
}
