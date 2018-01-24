#ifndef ISTEAMMATCHMAKING001_H
#define ISTEAMMATCHMAKING001_H 1

#include "steam.h"

#include "ISteamMatchmaking.h"

#define STEAMMATCHMAKING_INTERFACE_VERSION_001 "SteamMatchMaking001"

struct ISteamMatchmaking001
{
	int (*GetFavoriteGameCount)(struct ISteamMatchmakingImpl *This);
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

struct ISteamMatchmakingImpl *SteamMatchmaking001(void);

#endif /* ISTEAMMATCHMAKING001_H */
