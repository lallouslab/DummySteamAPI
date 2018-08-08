#include "macros.h"

#include "ISteamUGC007.h"
#include "ISteamUGC_priv.h"

static const struct ISteamUGC007Vtbl ISteamUGC007_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	ISteamUGC_CreateQueryUGCDetailsRequest,
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
	ISteamUGC_ReleaseQueryUGCRequest,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUGC_SetReturnMetadata,
	ISteamUGC_SetReturnChildren,
	ISteamUGC_SetReturnAdditionalPreviews,
	ISteamUGC_SetReturnTotalOnly,
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
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUGC *SteamUGC007(void)
{
	static struct ISteamUGCImpl impl;

	impl.base.vtbl.v007 = &ISteamUGC007_vtbl;

	return &impl.base;
}
