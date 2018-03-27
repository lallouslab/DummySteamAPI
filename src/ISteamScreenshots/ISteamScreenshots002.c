#include "macros.h"

#include "ISteamScreenshots002.h"
#include "ISteamScreenshots_priv.h"

static const struct ISteamScreenshots002Vtbl ISteamScreenshots002_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamScreenshots_HookScreenshots,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamScreenshots *SteamScreenshots002(void)
{
	static struct ISteamScreenshotsImpl impl;

	impl.base.vtbl.v002 = &ISteamScreenshots002_vtbl;

	return &impl.base;
}
