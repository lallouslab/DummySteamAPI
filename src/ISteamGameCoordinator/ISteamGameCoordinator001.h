#ifndef ISTEAMGAMECOORDINATOR001_H
#define ISTEAMGAMECOORDINATOR001_H 1

#include "steam.h"

#include "ISteamGameCoordinator.h"

#define STEAMGAMECOORDINATOR_INTERFACE_VERSION_001 "SteamGameCoordinator001"

struct ISteamGameCoordinator001Vtbl
{
	void *SendMessage;
	steam_bool_t (*IsMessageAvailable)(struct ISteamGameCoordinator *iface, uint32_t *msg_size);
	void *RetrieveMessage;
};

static inline struct ISteamGameCoordinator001Vtbl *get_ISteamGameCoordinator001Vtbl_from_ISteamGameCoordinator(struct ISteamGameCoordinator *iface) {
	return (struct ISteamGameCoordinator001Vtbl *)iface->vtbl;
}

struct ISteamGameCoordinator *SteamGameCoordinator001(void);

#endif /* ISTEAMGAMECOORDINATOR001_H */
