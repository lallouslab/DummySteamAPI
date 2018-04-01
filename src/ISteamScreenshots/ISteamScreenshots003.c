#include "macros.h"

#include "ISteamScreenshots003.h"
#include "ISteamScreenshots_priv.h"

static const struct ISteamScreenshots003Vtbl ISteamScreenshots003_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamScreenshots_HookScreenshots,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamScreenshots *SteamScreenshots003(void)
{
	static struct ISteamScreenshotsImpl impl;

	impl.base.vtbl.v003 = &ISteamScreenshots003_vtbl;

	return &impl.base;
}
