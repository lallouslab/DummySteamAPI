#include <string.h>

#include "debug.h"
#include "steam.h"

#include "ISteamFriends.h"
#include "ISteamFriends_priv.h"
#include "ISteamFriends001.h"
#include "ISteamFriends014.h"
#include "ISteamFriends015.h"

static const char *steam_friends_version = NULL;

const char *ISteamFriends_GetPersonaName(struct ISteamFriends *iface)
{
	struct ISteamFriendsImpl *This = impl_from_ISteamFriends(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return "Me";
}

steam_api_call_t ISteamFriends_SetPersonaName(struct ISteamFriends *iface, const char *name)
{
	struct ISteamFriendsImpl *This = impl_from_ISteamFriends(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));

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

steam_bool_t ISteamFriends_SetRichPresence(struct ISteamFriends *iface, const char *key, const char *value)
{
	struct ISteamFriendsImpl *This = impl_from_ISteamFriends(iface);

	LOG_ENTER_NOTIMPL("(This = %p, key = \"%s\", value = \"%s\")", VOIDPTR(This), debug_str(key), debug_str(value));

	return STEAM_TRUE;
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
		{ STEAMFRIENDS_INTERFACE_VERSION_015, SteamFriends015 },
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

	WARN("Unable to find ISteamFriends version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamFriends_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_friends_version)
		steam_friends_version = version;
}

EXPORT struct ISteamFriends *SteamFriends(void)
{
	static struct ISteamFriends *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_friends_version)
	{
		steam_friends_version = STEAMFRIENDS_INTERFACE_VERSION_015;

		WARN("ISteamFriends: No version specified, defaulting to \"%s\".", debug_str(steam_friends_version));
	}

	if (!cached_iface)
		cached_iface = SteamFriends_generic(steam_friends_version);

	return cached_iface;
}
