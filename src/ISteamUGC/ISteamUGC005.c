#include "macros.h"

#include "ISteamUGC005.h"
#include "ISteamUGC_priv.h"

static const struct ISteamUGC005Vtbl ISteamUGC005_vtbl = {
	INVAL_PTR,
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
	INVAL_PTR,
	INVAL_PTR,
	ISteamUGC_SetReturnChildren,
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
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUGC_GetNumSubscribedItems,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUGC *SteamUGC005(void)
{
	static struct ISteamUGCImpl impl;

	impl.base.vtbl.v005 = &ISteamUGC005_vtbl;

	return &impl.base;
}
