#include "utils.h"

#include "ISteamGameServer012.h"
#include "ISteamGameServer_priv.h"

static const struct ISteamGameServer012Vtbl ISteamGameServer012_vtbl = {
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
	ISteamGameServer_SetKeyValue,
	ISteamGameServer_SetGameTags,
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

struct ISteamGameServer *SteamGameServer012(void)
{
	static struct ISteamGameServerImpl impl;

	impl.base.vtbl.v012 = &ISteamGameServer012_vtbl;

	return &impl.base;
}
