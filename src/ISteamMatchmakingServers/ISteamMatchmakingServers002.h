#ifndef ISTEAMMATCHMAKINGSERVERS002_H
#define ISTEAMMATCHMAKINGSERVERS002_H 1

#include "steam.h"

#include "ISteamMatchmakingServers.h"

#define STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_002 "SteamMatchMakingServers002"

struct ISteamMatchmakingServers002Vtbl
{
	void *RequestInternetServerList;
	void *RequestLANServerList;
	void *RequestFriendsServerList;
	void *RequestFavoritesServerList;
	void *RequestHistoryServerList;
	void *RequestSpectatorServerList;
	void *ReleaseRequest;
	void *GetServerDetails;
	void (*CancelQuery)(struct ISteamMatchmakingServers *iface, steam_handle_server_list_request_t handle);
	void *RefreshQuery;
	steam_bool_t (*IsRefreshing)(struct ISteamMatchmakingServers *iface, steam_handle_server_list_request_t handle);
	void *GetServerCount;
	void *RefreshServer;
	void *PingServer;
	void *PlayerDetails;
	void *ServerRules;
	void *CancelServerQuery;
};

struct ISteamMatchmakingServers *SteamMatchmakingServers002(void);

#endif /* ISTEAMMATCHMAKINGSERVERS002_H */
