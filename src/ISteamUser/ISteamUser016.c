#include "macros.h"

#include "ISteamUser016.h"
#include "ISteamUser_priv.h"

static const struct ISteamUser016Vtbl ISteamUser016_vtbl = {
	ISteamUser_GetHSteamUser,
	ISteamUser_BLoggedOn,
	ISteamUser_GetSteamID,
	ISteamUser_InitiateGameConnection010,
	ISteamUser_TerminateGameConnection,
	INVAL_PTR,
	ISteamUser_GetUserDataFolder,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUser_GetAuthSessionTicket,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUser_CancelAuthTicket,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUser_AdvertiseGame,
	ISteamUser_RequestEncryptedAppTicket,
	INVAL_PTR,
};

struct ISteamUser *SteamUser016(void)
{
	static struct ISteamUserImpl impl;

	impl.base.vtbl.v016 = &ISteamUser016_vtbl;

	return &impl.base;
}
