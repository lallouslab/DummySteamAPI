#include "macros.h"

#include "ISteamInventory001.h"
#include "ISteamInventory_priv.h"

static const struct ISteamInventory001Vtbl ISteamInventory001_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamInventory *SteamInventory001(void)
{
	static struct ISteamInventoryImpl impl;

	impl.base.vtbl.v001 = &ISteamInventory001_vtbl;

	return &impl.base;
}
