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

struct ISteamClient006
{
	steam_handle_pipe_t (*CreateSteamPipe)(struct ISteamClient *This);
	void *BReleaseSteamPipe;
	void *CreateGlobalUser;
	void *ConnectToGlobalUser;
	void *CreateLocalUser;
	void *ReleaseUser;
	struct ISteamUserImpl *(*GetISteamUser)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetIVAC;
	struct ISteamGameServerImpl *(*GetISteamGameServer)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *SetLocalIPBinding;
	void *GetUniverseName;
	struct ISteamFriendsImpl *(*GetISteamFriends)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamUtilsImpl *(*GetISteamUtils)(struct ISteamClient *This, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetISteamBilling;
	struct ISteamMatchmakingImpl *(*GetISteamMatchmaking)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamApps *(*GetISteamApps)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetISteamContentServer;
	void *GetISteamMasterServerUpdater;
	struct ISteamMatchmakingServersImpl *(*GetISteamMatchmakingServers)(struct ISteamClient *This, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *RunFrame;
	void *GetIPCCallCount;
};

static inline struct ISteamClient006 *get_ISteamClient006_from_ISteamClient(struct ISteamClient *iface) {
	return (struct ISteamClient006 *)iface->iface;
}

struct ISteamClient *SteamClient006(void);

#endif /* ISTEAMCLIENT006_H */
