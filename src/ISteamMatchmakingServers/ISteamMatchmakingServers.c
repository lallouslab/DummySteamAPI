#include <string.h>

#include "debug.h"
#include "steam.h"

#include "ISteamMatchmakingServers.h"
#include "ISteamMatchmakingServers_priv.h"
#include "ISteamMatchmakingServers001.h"
#include "ISteamMatchmakingServers002.h"

static const char *steam_matchmaking_servers_version = NULL;

void ISteamMatchmakingServers_CancelQuery(struct ISteamMatchmakingServers *iface, steam_handle_server_list_request_t handle)
{
	struct ISteamMatchmakingServersImpl *This = impl_from_ISteamMatchmakingServers(iface);

	LOG_ENTER_NOTIMPL("(This = %p, handle = %p)", VOIDPTR(This), VOIDPTR(handle));
}

struct ISteamMatchmakingServers *SteamMatchmakingServers_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamMatchmakingServers *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_001, SteamMatchmakingServers001 },
		{ STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_002, SteamMatchmakingServers002 },
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

	WARN("Unable to find ISteamMatchmakingServers version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamMatchmakingServers_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_matchmaking_servers_version)
		steam_matchmaking_servers_version = version;
}

EXPORT struct ISteamMatchmakingServers *SteamMatchmakingServers(void)
{
	static struct ISteamMatchmakingServers *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_matchmaking_servers_version)
	{
		steam_matchmaking_servers_version = STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_002;

		WARN("ISteamMatchmakingServers: No version specified, defaulting to \"%s\".", debug_str(steam_matchmaking_servers_version));
	}

	if (!cached_iface)
		cached_iface = SteamMatchmakingServers_generic(steam_matchmaking_servers_version);

	return cached_iface;
}
