#include "macros.h"

#include "ISteamMatchmakingServers002.h"
#include "ISteamMatchmakingServers_priv.h"

static const struct ISteamMatchmakingServers002Vtbl ISteamMatchmakingServers002_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamMatchmakingServers_CancelQuery,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamMatchmakingServers *SteamMatchmakingServers002(void)
{
	static struct ISteamMatchmakingServersImpl impl;

	impl.base.vtbl.v002 = &ISteamMatchmakingServers002_vtbl;

	return &impl.base;
}
