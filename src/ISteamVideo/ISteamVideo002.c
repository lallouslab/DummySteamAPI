#include "macros.h"

#include "ISteamVideo002.h"
#include "ISteamVideo_priv.h"

static const struct ISteamVideo002Vtbl ISteamVideo002_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamVideo *SteamVideo002(void)
{
	static struct ISteamVideoImpl impl;

	impl.base.vtbl.v002 = &ISteamVideo002_vtbl;

	return &impl.base;
}
