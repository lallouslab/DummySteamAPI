#include "macros.h"

#include "ISteamGameServer011.h"
#include "ISteamGameServer_priv.h"

static const struct ISteamGameServer011Vtbl ISteamGameServer011_vtbl = {
	ISteamGameServer_InitGameServer,
	ISteamGameServer_SetProduct,
	ISteamGameServer_SetGameDescription,
	ISteamGameServer_SetModDir,
	ISteamGameServer_SetDedicatedServer,
	INVAL_PTR,
	ISteamGameServer_LogOnAnonymous,
	ISteamGameServer_LogOff,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamGameServer_SetMaxPlayerCount,
	ISteamGameServer_SetBotPlayerCount,
	ISteamGameServer_SetServerName,
	ISteamGameServer_SetMapName,
	ISteamGameServer_SetPasswordProtected,
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

struct ISteamGameServer *SteamGameServer011(void)
{
	static struct ISteamGameServerImpl impl;

	impl.base.vtbl.v011 = &ISteamGameServer011_vtbl;

	return &impl.base;
}
