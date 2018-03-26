#ifndef ISTEAMMATCHMAKING001_H
#define ISTEAMMATCHMAKING001_H 1

#include "steam.h"

#include "ISteamMatchmaking.h"

#define STEAMMATCHMAKING_INTERFACE_VERSION_001 "SteamMatchMaking001"

struct ISteamMatchmaking001Vtbl
{
	int (*GetFavoriteGameCount)(struct ISteamMatchmaking *iface);
	void *GetFavoriteGame;
	void *AddFavoriteGame;
	void *RemoveFavoriteGame;
	void *GetFavoriteGame2;
	void *AddFavoriteGame2;
	void *RemoveFavoriteGame2;
	void *RequestLobbyList;
	void *GetLobbyByIndex;
	void *CreateLobby;
	void *JoinLobby;
	void *LeaveLobby;
	void *InviteUserToLobby;
	void *GetNumLobbyMembers;
	void *GetLobbyMemberByIndex;
	void *GetLobbyData;
	void *SetLobbyData;
	void *GetLobbyMemberData;
	void *SetLobbyMemberData;
	void *SendLobbyChatMsg;
	void *GetLobbyChatEntry;
	void *RequestLobbyData;
};

struct ISteamMatchmaking *SteamMatchmaking001(void);

#endif /* ISTEAMMATCHMAKING001_H */
