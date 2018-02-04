#include <string.h>

#include "utils.h"

#include "ISteamFriends.h"
#include "ISteamFriends_priv.h"
#include "ISteamFriends001.h"
#include "ISteamFriends014.h"

const char *ISteamFriends_GetPersonaName(struct ISteamFriends *iface)
{
	struct ISteamFriendsImpl *This = impl_from_ISteamFriends(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return "Me";
}

steam_api_call_t ISteamFriends_SetPersonaName(struct ISteamFriends *iface, const char *name)
{
	struct ISteamFriendsImpl *This = impl_from_ISteamFriends(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = %s)", VOIDPTR(This), debug_str(name));

	return 0;
}

uint32_t ISteamFriends_GetPersonaState(struct ISteamFriends *iface)
{
	struct ISteamFriendsImpl *This = impl_from_ISteamFriends(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

int ISteamFriends_GetFriendCount(struct ISteamFriends *iface, int flags)
{
	struct ISteamFriendsImpl *This = impl_from_ISteamFriends(iface);

	LOG_ENTER_NOTIMPL("(This = %p, flags = %#x)", VOIDPTR(This), flags);

	return 0;
}

const char *ISteamFriends_GetFriendPersonaName(struct ISteamFriends *iface, void /* CSteamID */ *steam_id_friend)
{
	struct ISteamFriendsImpl *This = impl_from_ISteamFriends(iface);

	LOG_ENTER_NOTIMPL("(This = %p, steam_id_friend = %p)", VOIDPTR(This), steam_id_friend);

	return "";
}

steam_bool_t ISteamFriends_GetFriendGamePlayed(struct ISteamFriends *iface, void /* CSteamID */ *steam_id_friend, void /* FriendGameInfo_t */ *friend_game_info)
{
	struct ISteamFriendsImpl *This = impl_from_ISteamFriends(iface);

	LOG_ENTER_NOTIMPL("(This = %p, steam_id_friend = %p, friend_game_info = %p)", VOIDPTR(This), steam_id_friend, friend_game_info);

	return STEAM_FALSE;
}

steam_bool_t ISteamFriends_InviteUserToGame(struct ISteamFriends *iface, void /* CSteamID */ *steam_id_friend, const char *connect_str)
{
	struct ISteamFriendsImpl *This = impl_from_ISteamFriends(iface);

	LOG_ENTER_NOTIMPL("(This = %p, steam_id_friend = %p, connect_str = %p)", VOIDPTR(This), steam_id_friend, debug_str(connect_str));

	return STEAM_FALSE;
}

struct ISteamFriends *SteamFriends_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamFriends *(*iface_getter)(void);
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

EXPORT struct ISteamFriends *SteamFriends(void)
{
	LOG_ENTER0("()");

	return SteamFriends014();
}
