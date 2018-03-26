#include "utils.h"

#include "ISteamClient006.h"
#include "ISteamClient_priv.h"

static const struct ISteamClient006Vtbl ISteamClient006_vtbl = {
	ISteamClient_CreateSteamPipe,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamClient_GetISteamUser,
	INVAL_PTR,
	ISteamClient_GetISteamGameServer,
	INVAL_PTR,
	INVAL_PTR,
	ISteamClient_GetISteamFriends,
	ISteamClient_GetISteamUtils,
	INVAL_PTR,
	ISteamClient_GetISteamMatchmaking,
	ISteamClient_GetISteamApps,
	INVAL_PTR,
	INVAL_PTR,
	ISteamClient_GetISteamMatchmakingServers,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamClient *SteamClient006(void)
{
	static struct ISteamClientImpl impl;

	impl.base.vtbl.v006 = &ISteamClient006_vtbl;

	return &impl.base;
}
