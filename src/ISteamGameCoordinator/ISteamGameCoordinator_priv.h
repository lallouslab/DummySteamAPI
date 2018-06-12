#ifndef ISTEAMGAMECOORDINATOR_PRIV_H
#define ISTEAMGAMECOORDINATOR_PRIV_H 1

#include "steam.h"

#include "ISteamGameCoordinator.h"

struct ISteamGameCoordinatorImpl
{
	struct ISteamGameCoordinator base;
};

static inline struct ISteamGameCoordinatorImpl *impl_from_ISteamGameCoordinator(struct ISteamGameCoordinator *iface) {
	return CONTAINER_OF(iface, struct ISteamGameCoordinatorImpl, base);
}

MEMBER enum steam_game_coordinator_result ISteamGameCoordinator_SendMessage(struct ISteamGameCoordinator *iface, uint32_t msg_type, const void *msg, uint32_t msg_size);
MEMBER steam_bool_t ISteamGameCoordinator_IsMessageAvailable(struct ISteamGameCoordinator *iface, uint32_t *msg_size);

#endif /* ISTEAMGAMECOORDINATOR_PRIV_H */
