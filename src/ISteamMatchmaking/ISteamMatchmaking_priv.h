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

#endif /* ISTEAMMATCHMAKING_PRIV_H */
