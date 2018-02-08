#include <string.h>

#include "utils.h"

#include "ISteamGameServer.h"
#include "ISteamGameServer_priv.h"
#include "ISteamGameServer011.h"
#include "ISteamGameServer012.h"


static const char *steam_game_server_version = NULL;

struct ISteamGameServer *SteamGameServer_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamGameServer *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMGAMESERVER_INTERFACE_VERSION_011, SteamGameServer011 },
		{ STEAMGAMESERVER_INTERFACE_VERSION_012, SteamGameServer012 },
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

	WARN("Unable to find ISteamGameServer version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamGameServer_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_game_server_version)
		steam_game_server_version = version;
}

EXPORT struct ISteamGameServer *SteamGameServer(void)
{
	static struct ISteamGameServer *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_game_server_version)
	{
		steam_game_server_version = STEAMGAMESERVER_INTERFACE_VERSION_012;

		WARN("ISteamGameServer: No version specified, defaulting to \"%s\".", debug_str(steam_game_server_version));
	}

	if (!cached_iface)
		cached_iface = SteamGameServer_generic(steam_game_server_version);

	return cached_iface;
}
