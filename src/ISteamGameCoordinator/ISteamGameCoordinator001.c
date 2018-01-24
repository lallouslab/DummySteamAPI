#include "utils.h"

#include "ISteamGameCoordinator001.h"
#include "ISteamGameCoordinator_priv.h"

static const struct ISteamGameCoordinator001 ISteamGameCoordinator001_vtbl = {
	INVAL_PTR,
	ISteamGameCoordinator_IsMessageAvailable,
	INVAL_PTR
};

EXPORT struct ISteamGameCoordinatorImpl *SteamGameCoordinator001(void)
{
	static struct ISteamGameCoordinatorImpl impl;

	impl.iface = &ISteamGameCoordinator001_vtbl;

	return &impl;
}
