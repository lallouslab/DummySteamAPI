#include "utils.h"

#include "ISteamUser017.h"
#include "ISteamUser_priv.h"

static const struct ISteamUser017 ISteamUser017_vtbl = {
	ISteamUser_GetHSteamUser,
	ISteamUser_BLoggedOn,
	ISteamUser_GetSteamID,
	INVAL_PTR,
	INVAL_PTR,
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

struct ISteamUserImpl *SteamUser017(void)
{
	static struct ISteamUserImpl impl;

	impl.iface = &ISteamUser017_vtbl;

	return &impl;
}
