#ifndef ISTEAMCLIENT006_H
#define ISTEAMCLIENT006_H 1

#include "steam.h"

#include "ISteamClient.h"
#include "../ISteamApps/ISteamApps.h"
#include "../ISteamFriends/ISteamFriends.h"
#include "../ISteamGameServer/ISteamGameServer.h"
#include "../ISteamMatchmaking/ISteamMatchmaking.h"
#include "../ISteamMatchmakingServers/ISteamMatchmakingServers.h"
#include "../ISteamUser/ISteamUser.h"
#include "../ISteamUtils/ISteamUtils.h"

#define STEAMCLIENT_INTERFACE_VERSION_006 "SteamClient006"

struct ISteamClient006Vtbl
{
	MEMBER steam_handle_pipe_t (*CreateSteamPipe)(struct ISteamClient *iface);
	MEMBER steam_bool_t (*BReleaseSteamPipe)(struct ISteamClient *iface, steam_handle_pipe_t handle);
	void *CreateGlobalUser;
	void *ConnectToGlobalUser;
	void *CreateLocalUser;
	void *ReleaseUser;
	MEMBER struct ISteamUser *(*GetISteamUser)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetIVAC;
	MEMBER struct ISteamGameServer *(*GetISteamGameServer)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *SetLocalIPBinding;
	void *GetUniverseName;
	MEMBER struct ISteamFriends *(*GetISteamFriends)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamUtils *(*GetISteamUtils)(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetISteamBilling;
	MEMBER struct ISteamMatchmaking *(*GetISteamMatchmaking)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	MEMBER struct ISteamApps *(*GetISteamApps)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetISteamContentServer;
	void *GetISteamMasterServerUpdater;
	MEMBER struct ISteamMatchmakingServers *(*GetISteamMatchmakingServers)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *RunFrame;
	void *GetIPCCallCount;
};

struct ISteamClient *SteamClient006(void);

#endif /* ISTEAMCLIENT006_H */
