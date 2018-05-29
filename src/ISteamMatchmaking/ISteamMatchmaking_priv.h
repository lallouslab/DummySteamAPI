#ifndef ISTEAMMATCHMAKING_PRIV_H
#define ISTEAMMATCHMAKING_PRIV_H 1

#include "steam.h"

#include "ISteamMatchmaking.h"

struct ISteamMatchmakingImpl
{
	struct ISteamMatchmaking base;
};

static inline struct ISteamMatchmakingImpl *impl_from_ISteamMatchmaking(struct ISteamMatchmaking *iface) {
	return CONTAINER_OF(iface, struct ISteamMatchmakingImpl, base);
}

MEMBER int ISteamMatchmaking_GetFavoriteGameCount(struct ISteamMatchmaking *iface);
MEMBER void ISteamMatchmaking_AddRequestLobbyListResultCountFilter(struct ISteamMatchmaking *iface, int max_results);
MEMBER void ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter(struct ISteamMatchmaking *iface, union CSteamID steam_id_lobby);
MEMBER steam_api_call_t ISteamMatchmaking_CreateLobby007(struct ISteamMatchmaking *iface, enum steam_lobby_type type, int max_members);

#endif /* ISTEAMMATCHMAKING_PRIV_H */
