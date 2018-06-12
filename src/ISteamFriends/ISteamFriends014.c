#include "macros.h"

#include "ISteamFriends014.h"
#include "ISteamFriends_priv.h"

static const struct ISteamFriends014Vtbl ISteamFriends014_vtbl = {
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

struct ISteamFriends *SteamFriends014(void)
{
	static struct ISteamFriendsImpl impl;

	impl.base.vtbl.v014 = &ISteamFriends014_vtbl;

	return &impl.base;
}
