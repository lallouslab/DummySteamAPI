#include "isteamfriends.h"
#include "utils.h"

struct ISteamFriendsImpl
{
	const struct ISteamFriends *iface;
};

static const char *ISteamFriends_GetPersonaName(struct ISteamFriendsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return "Me";
}

static steam_delayed_return_t ISteamFriends_SetPersonaName(struct ISteamFriendsImpl *This, const char *name)
{
	log_enter_notimpl("(This = %p, name = %s)", VOIDPTR(This), debug_str(name));

	return 0;
}

static uint32_t ISteamFriends_GetPersonaState(struct ISteamFriendsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return 0;
}

static int ISteamFriends_GetFriendCount(struct ISteamFriendsImpl *This, int flags)
{
	log_enter_notimpl("(This = %p, flags = %#x)", VOIDPTR(This), flags);

	return 0;
}

static const struct ISteamFriends ISteamFriends_vtbl = {
	ISteamFriends_GetPersonaName,
	ISteamFriends_SetPersonaName,
	ISteamFriends_GetPersonaState,
	ISteamFriends_GetFriendCount
};

struct ISteamFriendsImpl *SteamFriends(void)
{
	static struct ISteamFriendsImpl impl;

	impl.iface = &ISteamFriends_vtbl;

	return &impl;
}
