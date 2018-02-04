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
	steam_handle_pipe_t (*CreateSteamPipe)(struct ISteamClient *iface);
	void *BReleaseSteamPipe;
	void *CreateGlobalUser;
	void *ConnectToGlobalUser;
	void *CreateLocalUser;
	void *ReleaseUser;
	struct ISteamUser *(*GetISteamUser)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetIVAC;
	struct ISteamGameServer *(*GetISteamGameServer)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *SetLocalIPBinding;
	void *GetUniverseName;
	struct ISteamFriends *(*GetISteamFriends)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamUtils *(*GetISteamUtils)(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetISteamBilling;
	struct ISteamMatchmaking *(*GetISteamMatchmaking)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	struct ISteamApps *(*GetISteamApps)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *GetISteamContentServer;
	void *GetISteamMasterServerUpdater;
	struct ISteamMatchmakingServers *(*GetISteamMatchmakingServers)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	void *RunFrame;
	void *GetIPCCallCount;
};

static inline struct ISteamClient006Vtbl *get_ISteamClient006Vtbl_from_ISteamClient(struct ISteamClient *iface) {
	return (struct ISteamClient006Vtbl *)iface->vtbl;
}

struct ISteamClient *SteamClient006(void);

#endif /* ISTEAMCLIENT006_H */
