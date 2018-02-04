#include "utils.h"

#include "ISteamUGC001.h"
#include "ISteamUGC_priv.h"

static const struct ISteamUGC001Vtbl ISteamUGC001_vtbl = {
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

struct ISteamUGC *SteamUGC001(void)
{
	static struct ISteamUGCImpl impl;

	impl.base.vtbl = &ISteamUGC001_vtbl;

	return &impl.base;
}
