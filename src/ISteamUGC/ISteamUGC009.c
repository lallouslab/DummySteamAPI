#include "macros.h"

#include "ISteamUGC009.h"
#include "ISteamUGC_priv.h"

static const struct ISteamUGC009Vtbl ISteamUGC009_vtbl = {
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
	ISteamUGC_SetReturnKeyValueTags,
	ISteamUGC_SetReturnLongDescription,
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
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUGC *SteamUGC009(void)
{
	static struct ISteamUGCImpl impl;

	impl.base.vtbl.v009 = &ISteamUGC009_vtbl;

	return &impl.base;
}
