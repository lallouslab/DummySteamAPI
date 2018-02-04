#include "utils.h"

#include "ISteamGameServerStats001.h"
#include "ISteamGameServerStats_priv.h"

static const struct ISteamGameServerStats001Vtbl ISteamGameServerStats001_vtbl = {
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

struct ISteamGameServerStats *SteamGameServerStats001(void)
{
	static struct ISteamGameServerStatsImpl impl;

	impl.base.vtbl = &ISteamGameServerStats001_vtbl;

	return &impl.base;
}