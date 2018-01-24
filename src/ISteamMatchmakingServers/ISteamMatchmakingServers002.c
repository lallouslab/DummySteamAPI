#include "utils.h"

#include "ISteamMatchmakingServers002.h"
#include "ISteamMatchmakingServers_priv.h"

static const struct ISteamMatchmakingServers002 ISteamMatchmakingServers002_vtbl = {
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

struct ISteamMatchmakingServersImpl *SteamMatchmakingServers002(void)
{
	static struct ISteamMatchmakingServersImpl impl;

	impl.iface = &ISteamMatchmakingServers002_vtbl;

	return &impl;
}
