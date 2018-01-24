#include "utils.h"

#include "ISteamGameServerStats001.h"
#include "ISteamGameServerStats_priv.h"

static const struct ISteamGameServerStats001 ISteamGameServerStats001_vtbl = {
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

struct ISteamGameServerStatsImpl *SteamGameServerStats001(void)
{
	static struct ISteamGameServerStatsImpl impl;

	impl.iface = &ISteamGameServerStats001_vtbl;

	return &impl;
}
