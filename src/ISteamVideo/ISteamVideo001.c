#include "macros.h"

#include "ISteamVideo001.h"
#include "ISteamVideo_priv.h"

static const struct ISteamVideo001Vtbl ISteamVideo001_vtbl = {
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamVideo *SteamVideo001(void)
{
	static struct ISteamVideoImpl impl;

	impl.base.vtbl.v001 = &ISteamVideo001_vtbl;

	return &impl.base;
}
