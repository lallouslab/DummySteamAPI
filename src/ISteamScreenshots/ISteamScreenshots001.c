#include "utils.h"

#include "ISteamScreenshots001.h"
#include "ISteamScreenshots_priv.h"

static const struct ISteamScreenshots001Vtbl ISteamScreenshots001_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamScreenshots_HookScreenshots,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamScreenshots *SteamScreenshots001(void)
{
	static struct ISteamScreenshotsImpl impl;

	impl.base.vtbl = &ISteamScreenshots001_vtbl;

	return &impl.base;
}
