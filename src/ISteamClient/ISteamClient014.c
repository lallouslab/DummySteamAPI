#include "utils.h"

#include "ISteamClient014.h"
#include "ISteamClient_priv.h"

static const struct ISteamClient014Vtbl ISteamClient014_vtbl = {
	ISteamClient_CreateSteamPipe,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
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
	ISteamClient_GetISteamUGC,
	ISteamClient_GetISteamAppList,
	ISteamClient_GetISteamMusic
};

struct ISteamClient *SteamClient014(void)
{
	static struct ISteamClientImpl impl;

	impl.base.vtbl = &ISteamClient014_vtbl;

	return &impl.base;
}
