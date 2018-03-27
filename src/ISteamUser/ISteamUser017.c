#include "utils.h"

#include "ISteamUser017.h"
#include "ISteamUser_priv.h"

static const struct ISteamUser017Vtbl ISteamUser017_vtbl = {
	ISteamUser_GetHSteamUser,
	ISteamUser_BLoggedOn,
	ISteamUser_GetSteamID,
	INVAL_PTR,
	ISteamUser_TerminateGameConnection,
	INVAL_PTR,
	ISteamUser_GetUserDataFolder,
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
