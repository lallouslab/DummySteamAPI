#include "macros.h"

#include "ISteamUser019.h"
#include "ISteamUser_priv.h"

static const struct ISteamUser019Vtbl ISteamUser019_vtbl = {
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
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUser *SteamUser019(void)
{
	static struct ISteamUserImpl impl;

	impl.base.vtbl.v019 = &ISteamUser019_vtbl;

	return &impl.base;
}
