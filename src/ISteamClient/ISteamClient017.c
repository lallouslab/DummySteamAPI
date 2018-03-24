#include "utils.h"

#include "ISteamClient017.h"
#include "ISteamClient_priv.h"

static const struct ISteamClient017Vtbl ISteamClient017_vtbl = {
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
	ISteamClient_GetISteamMusic,
	ISteamClient_GetISteamMusicRemote,
	ISteamClient_GetISteamHTMLSurface,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamClient_GetISteamInventory,
	ISteamClient_GetISteamVideo,
	INVAL_PTR
};

struct ISteamClient *SteamClient017(void)
{
	static struct ISteamClientImpl impl;

	impl.base.vtbl = &ISteamClient017_vtbl;

	return &impl.base;
}
