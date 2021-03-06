#include "macros.h"

#include "ISteamUGC010.h"
#include "ISteamUGC_priv.h"

static const struct ISteamUGC010Vtbl ISteamUGC010_vtbl = {
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
	ISteamUGC_SetReturnOnlyIDs,
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
	INVAL_PTR,
	ISteamUGC_GetNumSubscribedItems,
	ISteamUGC_GetSubscribedItems,
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

struct ISteamUGC *SteamUGC010(void)
{
	static struct ISteamUGCImpl impl;

	impl.base.vtbl.v010 = &ISteamUGC010_vtbl;

	return &impl.base;
}
