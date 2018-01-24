#include <stdio.h>
#include <string.h>

#include "utils.h"

#include "ISteamFriends.h"
#include "ISteamFriends_priv.h"
#include "ISteamFriends001.h"
#include "ISteamFriends014.h"

const char *ISteamFriends_GetPersonaName(struct ISteamFriendsImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return "Me";
}

steam_api_call_t ISteamFriends_SetPersonaName(struct ISteamFriendsImpl *This, const char *name)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s)", VOIDPTR(This), debug_str(name));

	return 0;
}

uint32_t ISteamFriends_GetPersonaState(struct ISteamFriendsImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

int ISteamFriends_GetFriendCount(struct ISteamFriendsImpl *This, int flags)
{
	LOG_ENTER_NOTIMPL("(This = %p, flags = %#x)", VOIDPTR(This), flags);

	return 0;
}

const char *ISteamFriends_GetFriendPersonaName(struct ISteamFriendsImpl *This, void /* CSteamID */ *steam_id_friend)
{
	LOG_ENTER_NOTIMPL("(This = %p, steam_id_friend = %p)", VOIDPTR(This), steam_id_friend);

	return "";
}

steam_bool_t ISteamFriends_GetFriendGamePlayed(struct ISteamFriendsImpl *This, void /* CSteamID */ *steam_id_friend, void /* FriendGameInfo_t */ *friend_game_info)
{
	LOG_ENTER_NOTIMPL("(This = %p, steam_id_friend = %p, friend_game_info = %p)", VOIDPTR(This), steam_id_friend, friend_game_info);

	return STEAM_FALSE;
}

steam_bool_t ISteamFriends_InviteUserToGame(struct ISteamFriendsImpl *This, void /* CSteamID */ *steam_id_friend, const char *connect_str)
{
	LOG_ENTER_NOTIMPL("(This = %p, steam_id_friend = %p, connect_str = %p)", VOIDPTR(This), steam_id_friend, debug_str(connect_str));

	return STEAM_FALSE;
}

struct ISteamFriendsImpl *SteamFriends_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamFriendsImpl *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMFRIENDS_INTERFACE_VERSION_001, SteamFriends001 },
		{ STEAMFRIENDS_INTERFACE_VERSION_014, SteamFriends014 },
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

	WARN("Unable to find ISteamFriends version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamFriendsImpl *SteamFriends(void)
{
	LOG_ENTER0("()");

	return SteamFriends014();
}
