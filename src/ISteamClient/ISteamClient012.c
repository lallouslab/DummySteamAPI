#include "macros.h"

#include "ISteamClient012.h"
#include "ISteamClient_priv.h"

static const struct ISteamClient012Vtbl ISteamClient012_vtbl = {
	ISteamClient_CreateSteamPipe,
	ISteamClient_BReleaseSteamPipe,
	ISteamClient_ConnectToGlobalUser,
	INVAL_PTR,
	ISteamClient_ReleaseUser,
	ISteamClient_GetISteamUser,
	ISteamClient_GetISteamGameServer,
	INVAL_PTR,
	ISteamClient_GetISteamFriends,
	ISteamClient_GetISteamUtils,
	ISteamClient_GetISteamMatchmaking,
	ISteamClient_GetISteamMatchmakingServers,
	ISteamClient_GetISteamGenericInterface,
	ISteamClient_GetISteamUserStats,
	ISteamClient_GetISteamGameServerStats,
	ISteamClient_GetISteamApps,
	ISteamClient_GetISteamNetworking,
	ISteamClient_GetISteamRemoteStorage,
	ISteamClient_GetISteamScreenshots,
	INVAL_PTR,
	INVAL_PTR,
	ISteamClient_SetWarningMessageHook,
	INVAL_PTR,
	ISteamClient_GetISteamHTTP,
	ISteamClient_GetISteamUnifiedMessages,
	ISteamClient_GetISteamController,
	ISteamClient_GetISteamUGC
};

struct ISteamClient *SteamClient012(void)
{
	static struct ISteamClientImpl impl;

	impl.base.vtbl.v012 = &ISteamClient012_vtbl;

	return &impl.base;
}
