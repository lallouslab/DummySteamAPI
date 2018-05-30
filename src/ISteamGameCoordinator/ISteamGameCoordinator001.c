#include "macros.h"

#include "ISteamGameCoordinator001.h"
#include "ISteamGameCoordinator_priv.h"

static const struct ISteamGameCoordinator001Vtbl ISteamGameCoordinator001_vtbl = {
	INVAL_PTR,
	ISteamGameCoordinator_IsMessageAvailable,
	INVAL_PTR
};

struct ISteamGameCoordinator *SteamGameCoordinator001(void)
{
	static struct ISteamGameCoordinatorImpl impl;

	impl.base.vtbl.v001 = &ISteamGameCoordinator001_vtbl;

	return &impl.base;
}
