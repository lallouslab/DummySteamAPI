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
	MEMBER steam_handle_pipe_t (*CreateSteamPipe)(struct ISteamClient *iface);
	MEMBER steam_bool_t (*BReleaseSteamPipe)(struct ISteamClient *iface, steam_handle_pipe_t handle);
	void *ConnectToGlobalUser;
	void *CreateLocalUser;
	void *ReleaseUser;
	MEMBER struct ISteamUser *(*GetISteamUser)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamGameServer *(*GetISteamGameServer)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *SetLocalIPBinding;
	MEMBER struct ISteamFriends *(*GetISteamFriends)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamUtils *(*GetISteamUtils)(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamMatchmaking *(*GetISteamMatchmaking)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamMatchmakingServers *(*GetISteamMatchmakingServers)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER void *(*GetISteamGenericInterface)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamUserStats *(*GetISteamUserStats)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamGameServerStats *(*GetISteamGameServerStats)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamApps *(*GetISteamApps)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamNetworking *(*GetISteamNetworking)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamRemoteStorage *(*GetISteamRemoteStorage)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamScreenshots *(*GetISteamScreenshots)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *RunFrame;
	void *GetIPCCallCount;
	MEMBER void (*SetWarningMessageHook)(struct ISteamClient *iface, void *callback);
	void *BShutdownIfAllPipesClosed;
	MEMBER struct ISteamHTTP *(*GetISteamHTTP)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamUnifiedMessages *(*GetISteamUnifiedMessages)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamController *(*GetISteamController)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamUGC *(*GetISteamUGC)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamAppList *(*GetISteamAppList)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamMusic *(*GetISteamMusic)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamMusicRemote *(*GetISteamMusicRemote)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamHTMLSurface *(*GetISteamHTMLSurface)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *Set_SteamAPI_CPostAPIResultInProcess;
	void *Remove_SteamAPI_CPostAPIResultInProcess;
	void *Set_SteamAPI_CCheckCallbackRegisteredInProcess;
	MEMBER struct ISteamInventory *(*GetISteamInventory)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamVideo *(*GetISteamVideo)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetISteamParentalSettings;
};

struct ISteamClient *SteamClient017(void);

#endif /* ISTEAMCLIENT017_H */
