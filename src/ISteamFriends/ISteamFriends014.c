#include "utils.h"

#include "ISteamFriends014.h"
#include "ISteamFriends_priv.h"

static const struct ISteamFriends014 ISteamFriends014_vtbl = {
	ISteamFriends_GetPersonaName,
	INVAL_PTR,
	ISteamFriends_GetPersonaState,
	ISteamFriends_GetFriendCount,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamFriends_GetFriendPersonaName,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamFriends_InviteUserToGame,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamFriendsImpl *SteamFriends014(void)
{
	static struct ISteamFriendsImpl impl;

	impl.iface = &ISteamFriends014_vtbl;

	return &impl;
}
