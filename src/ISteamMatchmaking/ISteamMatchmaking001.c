#include "utils.h"

#include "ISteamMatchmaking001.h"
#include "ISteamMatchmaking_priv.h"

static const struct ISteamMatchmaking001 ISteamMatchmaking001_vtbl = {
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

struct ISteamMatchmakingImpl *SteamMatchmaking001(void)
{
	static struct ISteamMatchmakingImpl impl;

	impl.iface = &ISteamMatchmaking001_vtbl;

	return &impl;
}
