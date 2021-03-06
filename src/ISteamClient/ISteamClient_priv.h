#ifndef ISTEAMCLIENT_PRIV_H
#define ISTEAMCLIENT_PRIV_H 1

#include "steam.h"

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

MEMBER steam_handle_pipe_t ISteamClient_CreateSteamPipe(struct ISteamClient *iface);
MEMBER steam_bool_t ISteamClient_BReleaseSteamPipe(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe);
MEMBER steam_user_t ISteamClient_ConnectToGlobalUser(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe);
MEMBER void ISteamClient_ReleaseUser(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, steam_user_t steam_user);
MEMBER struct ISteamAppList *ISteamClient_GetISteamAppList(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamApps *ISteamClient_GetISteamApps(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamClient *ISteamClient_GetISteamClient(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamController *ISteamClient_GetISteamController(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamFriends *ISteamClient_GetISteamFriends(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamGameCoordinator *ISteamClient_GetISteamGameCoordinator(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamGameServer *ISteamClient_GetISteamGameServer(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamGameServerStats *ISteamClient_GetISteamGameServerStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER void *ISteamClient_GetISteamGenericInterface(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamHTMLSurface *ISteamClient_GetISteamHTMLSurface(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamHTTP *ISteamClient_GetISteamHTTP(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamInventory *ISteamClient_GetISteamInventory(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamMatchmaking *ISteamClient_GetISteamMatchmaking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamMatchmakingServers *ISteamClient_GetISteamMatchmakingServers(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamMusic *ISteamClient_GetISteamMusic(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamMusicRemote *ISteamClient_GetISteamMusicRemote(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamNetworking *ISteamClient_GetISteamNetworking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamParentalSettings *ISteamClient_GetISteamParentalSettings(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamRemoteStorage *ISteamClient_GetISteamRemoteStorage(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamScreenshots *ISteamClient_GetISteamScreenshots(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamUGC *ISteamClient_GetISteamUGC(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamUnifiedMessages *ISteamClient_GetISteamUnifiedMessages(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamUser *ISteamClient_GetISteamUser(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamUserStats *ISteamClient_GetISteamUserStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamUtils *ISteamClient_GetISteamUtils(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER struct ISteamVideo *ISteamClient_GetISteamVideo(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
MEMBER void ISteamClient_SetWarningMessageHook(struct ISteamClient *iface, void *callback);

#endif /* ISTEAMCLIENT_PRIV_H */
