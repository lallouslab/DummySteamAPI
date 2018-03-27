#include "utils.h"

#include "ISteamUser018.h"
#include "ISteamUser_priv.h"

static const struct ISteamUser018Vtbl ISteamUser018_vtbl = {
	ISteamUser_GetHSteamUser,
	ISteamUser_BLoggedOn,
	ISteamUser_GetSteamID018,
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
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUser *SteamUser018(void)
{
	static struct ISteamUserImpl impl;

	impl.base.vtbl.v018 = &ISteamUser018_vtbl;

	return &impl.base;
}
