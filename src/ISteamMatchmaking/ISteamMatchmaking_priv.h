#ifndef ISTEAMMATCHMAKING_PRIV_H
#define ISTEAMMATCHMAKING_PRIV_H 1

#include "steam.h"

struct ISteamMatchmakingImpl
{
	const void *iface;
};

int ISteamMatchmaking_GetFavoriteGameCount(struct ISteamMatchmakingImpl *This);

#endif /* ISTEAMMATCHMAKING_PRIV_H */
