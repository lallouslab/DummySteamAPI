#ifndef ISTEAMCLIENT_PRIV_H
#define ISTEAMCLIENT_PRIV_H 1

#include "steam.h"
#include "utils.h"

#include "../ISteamAppList/ISteamAppList.h"
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
#include "../ISteamMusic/ISteamMusic.h"
#include "../ISteamMusicRemote/ISteamMusicRemote.h"
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

steam_handle_pipe_t ISteamClient_CreateSteamPipe(struct ISteamClient *iface);
struct ISteamAppList *ISteamClient_GetISteamAppList(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamApps *ISteamClient_GetISteamApps(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamClient *ISteamClient_GetISteamClient(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamController *ISteamClient_GetISteamController(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamFriends *ISteamClient_GetISteamFriends(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamGameCoordinator *ISteamClient_GetISteamGameCoordinator(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamGameServer *ISteamClient_GetISteamGameServer(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamGameServerStats *ISteamClient_GetISteamGameServerStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
void *ISteamClient_GetISteamGenericInterface(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamHTTP *ISteamClient_GetISteamHTTP(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamMatchmaking *ISteamClient_GetISteamMatchmaking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamMatchmakingServers *ISteamClient_GetISteamMatchmakingServers(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamMusic *ISteamClient_GetISteamMusic(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamMusicRemote *ISteamClient_GetISteamMusicRemote(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamNetworking *ISteamClient_GetISteamNetworking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamRemoteStorage *ISteamClient_GetISteamRemoteStorage(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamScreenshots *ISteamClient_GetISteamScreenshots(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamUGC *ISteamClient_GetISteamUGC(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamUnifiedMessages *ISteamClient_GetISteamUnifiedMessages(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamUser *ISteamClient_GetISteamUser(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamUserStats *ISteamClient_GetISteamUserStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
struct ISteamUtils *ISteamClient_GetISteamUtils(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version);
void ISteamClient_SetWarningMessageHook(struct ISteamClient *iface, void *callback);

#endif /* ISTEAMCLIENT_PRIV_H */
