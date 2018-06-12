#include "macros.h"

#include "ISteamFriends013.h"
#include "ISteamFriends_priv.h"

static const struct ISteamFriends013Vtbl ISteamFriends013_vtbl = {
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
	ISteamFriends_GetMediumFriendAvatar,
	ISteamFriends_GetLargeFriendAvatar,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamFriends_SetRichPresence,
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

struct ISteamFriends *SteamFriends013(void)
{
	static struct ISteamFriendsImpl impl;

	impl.base.vtbl.v013 = &ISteamFriends013_vtbl;

	return &impl.base;
}
