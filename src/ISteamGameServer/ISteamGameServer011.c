#include "utils.h"

#include "ISteamGameServer011.h"
#include "ISteamGameServer_priv.h"

static const struct ISteamGameServer011Vtbl ISteamGameServer011_vtbl = {
	ISteamGameServer_InitGameServer,
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
	ISteamGameServer_CreateUnauthenticatedUserConnection,
	ISteamGameServer_SendUserDisconnect,
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
	ISteamGameServer_EnableHeartbeats,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamGameServer *SteamGameServer011(void)
{
	static struct ISteamGameServerImpl impl;

	impl.base.vtbl.v011 = &ISteamGameServer011_vtbl;

	return &impl.base;
}
