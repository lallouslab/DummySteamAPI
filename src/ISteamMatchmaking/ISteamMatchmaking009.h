#ifndef ISTEAMMATCHMAKING009_H
#define ISTEAMMATCHMAKING009_H 1

#include "steam.h"

#include "ISteamMatchmaking.h"

#define STEAMMATCHMAKING_INTERFACE_VERSION_009 "SteamMatchMaking009"

struct ISteamMatchmaking009
{
	int (*GetFavoriteGameCount)(struct ISteamMatchmakingImpl *This);
	void *GetFavoriteGame;
	void *AddFavoriteGame;
	void *RemoveFavoriteGame;
	void *RequestLobbyList;
	void *AddRequestLobbyListStringFilter;
	void *AddRequestLobbyListNumericalFilter;
	void *AddRequestLobbyListNearValueFilter;
	void *AddRequestLobbyListFilterSlotsAvailable;
	void *AddRequestLobbyListDistanceFilter;
	void *AddRequestLobbyListResultCountFilter;
	void *AddRequestLobbyListCompatibleMembersFilter;
	void *GetLobbyByIndex;
	void *CreateLobby;
	void *JoinLobby;
	void *LeaveLobby;
	void *InviteUserToLobby;
	void *GetNumLobbyMembers;
	void *GetLobbyMemberByIndex;
	void *GetLobbyData;
	void *SetLobbyData;
	void *GetLobbyDataCount;
	void *GetLobbyDataByIndex;
	void *DeleteLobbyData;
	void *GetLobbyMemberData;
	void *SetLobbyMemberData;
	void *SendLobbyChatMsg;
	void *GetLobbyChatEntry;
	void *RequestLobbyData;
	void *SetLobbyGameServer;
	void *GetLobbyGameServer;
	void *SetLobbyMemberLimit;
	void *GetLobbyMemberLimit;
	void *SetLobbyType;
	void *SetLobbyJoinable;
	void *GetLobbyOwner;
	void *SetLobbyOwner;
	void *SetLinkedLobby;
};

struct ISteamMatchmakingImpl *SteamMatchmaking009(void);

#endif /* ISTEAMMATCHMAKING009_H */
