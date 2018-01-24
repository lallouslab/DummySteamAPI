#include <stdio.h>
#include <string.h>

#include "utils.h"

#include "ISteamGameServer.h"
#include "ISteamGameServer_priv.h"
#include "ISteamGameServer011.h"
#include "ISteamGameServer012.h"

const char *ISteamGameServer_GetPersonaName(struct ISteamGameServerImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return "Me";
}

steam_api_call_t ISteamGameServer_SetPersonaName(struct ISteamGameServerImpl *This, const char *name)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s)", VOIDPTR(This), debug_str(name));

	return 0;
}

uint32_t ISteamGameServer_GetPersonaState(struct ISteamGameServerImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

int ISteamGameServer_GetFriendCount(struct ISteamGameServerImpl *This, int flags)
{
	LOG_ENTER_NOTIMPL("(This = %p, flags = %#x)", VOIDPTR(This), flags);

	return 0;
}

const char *ISteamGameServer_GetFriendPersonaName(struct ISteamGameServerImpl *This, void /* CSteamID */ *steam_id_friend)
{
	LOG_ENTER_NOTIMPL("(This = %p, steam_id_friend = %p)", VOIDPTR(This), steam_id_friend);

	return "";
}

steam_bool_t ISteamGameServer_GetFriendGamePlayed(struct ISteamGameServerImpl *This, void /* CSteamID */ *steam_id_friend, void /* FriendGameInfo_t */ *friend_game_info)
{
	LOG_ENTER_NOTIMPL("(This = %p, steam_id_friend = %p, friend_game_info = %p)", VOIDPTR(This), steam_id_friend, friend_game_info);

	return STEAM_FALSE;
}

struct ISteamGameServerImpl *SteamGameServer_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamGameServerImpl *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMGAMESERVER_INTERFACE_VERSION_011, SteamGameServer011 },
		{ STEAMGAMESERVER_INTERFACE_VERSION_012, SteamGameServer012 },
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

	WARN("Unable to find ISteamGameServer version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamGameServerImpl *SteamGameServer(void)
{
	LOG_ENTER0("()");

	return SteamGameServer012();
}
