#ifndef ISTEAMCLIENT017_H
#define ISTEAMCLIENT017_H 1

#include "steam.h"

#include "ISteamClient.h"
#include "../ISteamAppList/ISteamAppList.h"
#include "../ISteamApps/ISteamApps.h"
#include "../ISteamFriends/ISteamFriends.h"
#include "../ISteamGameCoordinator/ISteamGameCoordinator.h"
#include "../ISteamGameServer/ISteamGameServer.h"
#include "../ISteamMatchmaking/ISteamMatchmaking.h"
#include "../ISteamMatchmakingServers/ISteamMatchmakingServers.h"
#include "../ISteamMusic/ISteamMusic.h"
#include "../ISteamMusicRemote/ISteamMusicRemote.h"
#include "../ISteamNetworking/ISteamNetworking.h"
#include "../ISteamUser/ISteamUser.h"
#include "../ISteamUserStats/ISteamUserStats.h"
#include "../ISteamUtils/ISteamUtils.h"

#define STEAMCLIENT_INTERFACE_VERSION_017 "SteamClient017"

struct ISteamClient017Vtbl
{
	steam_handle_pipe_t (*CreateSteamPipe)(struct ISteamClient *iface);
	void *BReleaseSteamPipe;
	void *ConnectToGlobalUser;
	void *CreateLocalUser;
	void *ReleaseUser;
	struct ISteamUser *(*GetISteamUser)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamGameServer *(*GetISteamGameServer)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *SetLocalIPBinding;
	struct ISteamFriends *(*GetISteamFriends)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamUtils *(*GetISteamUtils)(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamMatchmaking *(*GetISteamMatchmaking)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamMatchmakingServers *(*GetISteamMatchmakingServers)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *(*GetISteamGenericInterface)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamUserStats *(*GetISteamUserStats)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamGameServerStats *(*GetISteamGameServerStats)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamApps *(*GetISteamApps)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamNetworking *(*GetISteamNetworking)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamRemoteStorage *(*GetISteamRemoteStorage)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamScreenshots *(*GetISteamScreenshots)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *RunFrame;
	void *GetIPCCallCount;
	void (*SetWarningMessageHook)(struct ISteamClient *iface, void *callback);
	void *BShutdownIfAllPipesClosed;
	struct ISteamHTTP *(*GetISteamHTTP)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamUnifiedMessages *(*GetISteamUnifiedMessages)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamController *(*GetISteamController)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamUGC *(*GetISteamUGC)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamAppList *(*GetISteamAppList)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamMusic *(*GetISteamMusic)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamMusicRemote *(*GetISteamMusicRemote)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamHTMLSurface *(*GetISteamHTMLSurface)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *Set_SteamAPI_CPostAPIResultInProcess;
	void *Remove_SteamAPI_CPostAPIResultInProcess;
	void *Set_SteamAPI_CCheckCallbackRegisteredInProcess;
	struct ISteamInventory *(*GetISteamInventory)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamVideo *(*GetISteamVideo)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetISteamParentalSettings;
};

static inline struct ISteamClient017Vtbl *get_ISteamClient017Vtbl_from_ISteamClient(struct ISteamClient *iface) {
	return (struct ISteamClient017Vtbl *)iface->vtbl;
}

struct ISteamClient *SteamClient017(void);

#endif /* ISTEAMCLIENT017_H */
