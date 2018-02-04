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
	void *CancelQuery;
	void *RefreshQuery;
	void *IsRefreshing;
	void *GetServerCount;
	void *RefreshServer;
	void *PingServer;
	void *PlayerDetails;
	void *ServerRules;
	void *CancelServerQuery;
};

static inline struct ISteamMatchmakingServers002Vtbl *get_ISteamMatchmakingServers002Vtbl_from_ISteamMatchmakingServers(struct ISteamMatchmakingServers *iface) {
	return (struct ISteamMatchmakingServers002Vtbl *)iface->vtbl;
}

struct ISteamMatchmakingServers *SteamMatchmakingServers002(void);

#endif /* ISTEAMMATCHMAKINGSERVERS002_H */