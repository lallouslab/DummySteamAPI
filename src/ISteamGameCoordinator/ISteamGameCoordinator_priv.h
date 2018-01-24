#ifndef ISTEAMGAMECOORDINATOR_PRIV_H
#define ISTEAMGAMECOORDINATOR_PRIV_H 1

#include "steam.h"

struct ISteamGameCoordinatorImpl
{
	const void *iface;
};

steam_bool_t ISteamGameCoordinator_IsMessageAvailable(struct ISteamGameCoordinatorImpl *This, uint32_t *msg_size);

#endif /* ISTEAMGAMECOORDINATOR_PRIV_H */
