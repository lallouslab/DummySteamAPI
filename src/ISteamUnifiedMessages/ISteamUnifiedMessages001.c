#include "utils.h"

#include "ISteamUnifiedMessages001.h"
#include "ISteamUnifiedMessages_priv.h"

static const struct ISteamUnifiedMessages001Vtbl ISteamUnifiedMessages001_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

EXPORT struct ISteamUnifiedMessages *SteamUnifiedMessages001(void)
{
	static struct ISteamUnifiedMessagesImpl impl;

	impl.base.vtbl.v001 = &ISteamUnifiedMessages001_vtbl;

	return &impl.base;
}
