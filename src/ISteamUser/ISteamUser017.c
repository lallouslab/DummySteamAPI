#include "macros.h"

#include "ISteamUser017.h"
#include "ISteamUser_priv.h"

static const struct ISteamUser017Vtbl ISteamUser017_vtbl = {
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
	ISteamUser_BIsBehindNAT,
	ISteamUser_AdvertiseGame,
	ISteamUser_RequestEncryptedAppTicket,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUser *SteamUser017(void)
{
	static struct ISteamUserImpl impl;

	impl.base.vtbl.v017 = &ISteamUser017_vtbl;

	return &impl.base;
}
