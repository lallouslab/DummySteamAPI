#ifndef ISTEAMMATCHMAKINGSERVERS001_H
#define ISTEAMMATCHMAKINGSERVERS001_H 1

#include "steam.h"

#include "ISteamMatchmakingServers.h"

#define STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_001 "SteamMatchMakingServers001"

struct ISteamMatchmakingServers001
{
	void *RequestInternetServerList;
	void *RequestLANServerList;
	void *RequestFriendsServerList;
	void *RequestFavoritesServerList;
	void *RequestHistoryServerList;
	void *RequestSpectatorServerList;
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

struct ISteamMatchmakingServersImpl *SteamMatchmakingServers001(void);

#endif /* ISTEAMMATCHMAKINGSERVERS001_H */
