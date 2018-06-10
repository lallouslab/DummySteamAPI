#include "macros.h"

#include "ISteamUGC001.h"
#include "ISteamUGC_priv.h"

static const struct ISteamUGC001Vtbl ISteamUGC001_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	ISteamUGC_SendQueryUGCRequest,
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

	impl.base.vtbl.v001 = &ISteamUGC001_vtbl;

	return &impl.base;
}
