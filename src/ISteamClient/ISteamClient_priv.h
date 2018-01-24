#ifndef ISTEAMCLIENT_PRIV_H
#define ISTEAMCLIENT_PRIV_H 1

#include "steam.h"
#include "utils.h"

#include "../ISteamApps/ISteamApps.h"
#include "../ISteamClient/ISteamClient.h"
#include "../ISteamController/ISteamController.h"
#include "../ISteamFriends/ISteamFriends.h"
#include "../ISteamGameCoordinator/ISteamGameCoordinator.h"
#include "../ISteamGameServer/ISteamGameServer.h"
#include "../ISteamGameServerStats/ISteamGameServerStats.h"
#include "../ISteamHTTP/ISteamHTTP.h"
#include "../ISteamMatchmaking/ISteamMatchmaking.h"
#include "../ISteamMatchmakingServers/ISteamMatchmakingServers.h"
#include "../ISteamNetworking/ISteamNetworking.h"
#include "../ISteamRemoteStorage/ISteamRemoteStorage.h"
#include "../ISteamScreenshots/ISteamScreenshots.h"
#include "../ISteamUGC/ISteamUGC.h"
#include "../ISteamUnifiedMessages/ISteamUnifiedMessages.h"
#include "../ISteamUser/ISteamUser.h"
#include "../ISteamUserStats/ISteamUserStats.h"
#include "../ISteamUtils/ISteamUtils.h"

struct ISteamClientImpl
{
	struct ISteamClient base;
};

static inline struct ISteamClientImpl *impl_from_ISteamClient(struct ISteamClient *iface) {
	return CONTAINER_OF(iface, struct ISteamClientImpl, base);
}

steam_handle_pipe_t ISteamClient_CreateSteamPipe(struct ISteamClient *This);
struct ISteamApps *ISteamClient_GetISteamApps(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamClient *ISteamClient_GetISteamClient(struct ISteamClient *This, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamControllerImpl *ISteamClient_GetISteamController(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamFriendsImpl *ISteamClient_GetISteamFriends(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamGameCoordinatorImpl *ISteamClient_GetISteamGameCoordinator(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamGameServerImpl *ISteamClient_GetISteamGameServer(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamGameServerStatsImpl *ISteamClient_GetISteamGameServerStats(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
void *ISteamClient_GetISteamGenericInterface(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamHTTPImpl *ISteamClient_GetISteamHTTP(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamMatchmakingImpl *ISteamClient_GetISteamMatchmaking(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamMatchmakingServersImpl *ISteamClient_GetISteamMatchmakingServers(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamNetworkingImpl *ISteamClient_GetISteamNetworking(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamRemoteStorageImpl *ISteamClient_GetISteamRemoteStorage(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamScreenshotsImpl *ISteamClient_GetISteamScreenshots(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamUGC *ISteamClient_GetISteamUGC(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamUnifiedMessagesImpl *ISteamClient_GetISteamUnifiedMessages(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamUserImpl *ISteamClient_GetISteamUser(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamUserStatsImpl *ISteamClient_GetISteamUserStats(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamUtilsImpl *ISteamClient_GetISteamUtils(struct ISteamClient *This, steam_handle_pipe_t steam_pipe, const char *version);
void ISteamClient_SetWarningMessageHook(struct ISteamClient *This, void *callback);

#endif /* ISTEAMCLIENT_PRIV_H */
