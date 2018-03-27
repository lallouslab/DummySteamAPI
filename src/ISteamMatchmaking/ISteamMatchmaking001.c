#include "macros.h"

#include "ISteamMatchmaking001.h"
#include "ISteamMatchmaking_priv.h"

static const struct ISteamMatchmaking001Vtbl ISteamMatchmaking001_vtbl = {
	ISteamMatchmaking_GetFavoriteGameCount,
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
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamMatchmaking *SteamMatchmaking001(void)
{
	static struct ISteamMatchmakingImpl impl;

	impl.base.vtbl.v001 = &ISteamMatchmaking001_vtbl;

	return &impl.base;
}
