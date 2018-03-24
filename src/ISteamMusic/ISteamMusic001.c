#include "utils.h"

#include "ISteamMusic001.h"
#include "ISteamMusic_priv.h"

static const struct ISteamMusic001Vtbl ISteamMusic001_vtbl = {
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

struct ISteamMusic *SteamMusic001(void)
{
	static struct ISteamMusicImpl impl;

	impl.base.vtbl = &ISteamMusic001_vtbl;

	return &impl.base;
}
