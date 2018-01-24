#include "utils.h"

#include "ISteamMatchmakingServers001.h"
#include "ISteamMatchmakingServers_priv.h"

static const struct ISteamMatchmakingServers001 ISteamMatchmakingServers001_vtbl = {
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

struct ISteamMatchmakingServersImpl *SteamMatchmakingServers001(void)
{
	static struct ISteamMatchmakingServersImpl impl;

	impl.iface = &ISteamMatchmakingServers001_vtbl;

	return &impl;
}
