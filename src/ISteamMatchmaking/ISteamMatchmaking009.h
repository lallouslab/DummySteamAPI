#ifndef ISTEAMMATCHMAKING009_H
#define ISTEAMMATCHMAKING009_H 1

#include "steam.h"

#include "ISteamMatchmaking.h"

#define STEAMMATCHMAKING_INTERFACE_VERSION_009 "SteamMatchMaking009"

struct ISteamMatchmaking009Vtbl
{
	MEMBER int (*GetFavoriteGameCount)(struct ISteamMatchmaking *iface);
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
	MEMBER void (*AddRequestLobbyListCompatibleMembersFilter)(struct ISteamMatchmaking *iface, union CSteamID steam_id_lobby);
	void *GetLobbyByIndex;
	MEMBER steam_api_call_t (*CreateLobby)(struct ISteamMatchmaking *iface, enum steam_lobby_type type, int max_members);
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

struct ISteamMatchmaking *SteamMatchmaking009(void);

#endif /* ISTEAMMATCHMAKING009_H */
