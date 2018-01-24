#include "utils.h"

#include "ISteamUser004.h"
#include "ISteamUser_priv.h"

static const struct ISteamUser004 ISteamUser004_vtbl = {
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
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUserImpl *SteamUser004(void)
{
	static struct ISteamUserImpl impl;

	impl.iface = &ISteamUser004_vtbl;

	return &impl;
}
