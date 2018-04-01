#include "macros.h"

#include "ISteamUser004.h"
#include "ISteamUser_priv.h"

static const struct ISteamUser004Vtbl ISteamUser004_vtbl = {
	ISteamUser_GetHSteamUser,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUser_BLoggedOn,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUser_GetSteamID,
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
	ISteamUser_InitiateGameConnection,
	ISteamUser_TerminateGameConnection,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUser *SteamUser004(void)
{
	static struct ISteamUserImpl impl;

	impl.base.vtbl.v004 = &ISteamUser004_vtbl;

	return &impl.base;
}
