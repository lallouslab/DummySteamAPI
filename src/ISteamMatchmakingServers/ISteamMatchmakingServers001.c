#include "macros.h"

#include "ISteamMatchmakingServers001.h"
#include "ISteamMatchmakingServers_priv.h"

static const struct ISteamMatchmakingServers001Vtbl ISteamMatchmakingServers001_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamMatchmakingServers_CancelQuery,
	INVAL_PTR,
	ISteamMatchmakingServers_IsRefreshing,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamMatchmakingServers *SteamMatchmakingServers001(void)
{
	static struct ISteamMatchmakingServersImpl impl;

	impl.base.vtbl.v001 = &ISteamMatchmakingServers001_vtbl;

	return &impl.base;
}
