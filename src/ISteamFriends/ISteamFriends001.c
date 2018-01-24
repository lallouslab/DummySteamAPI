#include "utils.h"

#include "ISteamFriends001.h"
#include "ISteamFriends_priv.h"

static const struct ISteamFriends001 ISteamFriends001_vtbl = {
	ISteamFriends_GetPersonaName,
	INVAL_PTR,
	ISteamFriends_GetPersonaState,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
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
	INVAL_PTR
};

struct ISteamFriendsImpl *SteamFriends001(void)
{
	static struct ISteamFriendsImpl impl;

	impl.iface = &ISteamFriends001_vtbl;

	return &impl;
}
