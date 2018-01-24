#ifndef ISTEAMCLIENT016_H
#define ISTEAMCLIENT016_H 1

#include "steam.h"

#include "ISteamClient.h"
#include "../ISteamApps/ISteamApps.h"
#include "../ISteamFriends/ISteamFriends.h"
#include "../ISteamGameCoordinator/ISteamGameCoordinator.h"
#include "../ISteamGameServer/ISteamGameServer.h"
#include "../ISteamMatchmaking/ISteamMatchmaking.h"
#include "../ISteamMatchmakingServers/ISteamMatchmakingServers.h"
#include "../ISteamNetworking/ISteamNetworking.h"
#include "../ISteamUser/ISteamUser.h"
#include "../ISteamUserStats/ISteamUserStats.h"
#include "../ISteamUtils/ISteamUtils.h"

#define STEAMCLIENT_INTERFACE_VERSION_016 "SteamClient016"

struct ISteamClient016
{
	steam_handle_pipe_t (*CreateSteamPipe)(struct ISteamClient *This);
	void *BReleaseSteamPipe;
	void *ConnectToGlobalUser;
	void *CreateLocalUser;
	void *ReleaseUser;
	struct ISteamUserImpl *(*GetISteamUser)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamGameServerImpl *(*GetISteamGameServer)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *SetLocalIPBinding;
	struct ISteamFriendsImpl *(*GetISteamFriends)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamUtilsImpl *(*GetISteamUtils)(struct ISteamClient *This, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamMatchmakingImpl *(*GetISteamMatchmaking)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamMatchmakingServersImpl *(*GetISteamMatchmakingServers)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *(*GetISteamGenericInterface)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamUserStatsImpl *(*GetISteamUserStats)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamGameServerStatsImpl *(*GetISteamGameServerStats)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamApps *(*GetISteamApps)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamNetworkingImpl *(*GetISteamNetworking)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamRemoteStorageImpl *(*GetISteamRemoteStorage)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamScreenshotsImpl *(*GetISteamScreenshots)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *RunFrame;
	void *GetIPCCallCount;
	void (*SetWarningMessageHook)(struct ISteamClient *This, void *callback);
	void *BShutdownIfAllPipesClosed;
	struct ISteamHTTPImpl *(*GetISteamHTTP)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamUnifiedMessagesImpl *(*GetISteamUnifiedMessages)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamControllerImpl *(*GetISteamController)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamUGC *(*GetISteamUGC)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetISteamAppList;
	void *GetISteamMusic;
	void *GetISteamMusicRemote;
	void *GetISteamHTMLSurface;
	void *Set_SteamAPI_CPostAPIResultInProcess;
	void *Remove_SteamAPI_CPostAPIResultInProcess;
	void *Set_SteamAPI_CCheckCallbackRegisteredInProcess;
};

static inline struct ISteamClient016 *get_ISteamClient016_from_ISteamClient(struct ISteamClient *iface) {
	return (struct ISteamClient016 *)iface->iface;
}

struct ISteamClient *SteamClient016(void);

#endif /* ISTEAMCLIENT016_H */
