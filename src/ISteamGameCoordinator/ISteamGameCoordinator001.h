#ifndef ISTEAMGAMECOORDINATOR001_H
#define ISTEAMGAMECOORDINATOR001_H 1

#include "steam.h"

#include "ISteamGameCoordinator.h"

#define STEAMGAMECOORDINATOR_INTERFACE_VERSION_001 "SteamGameCoordinator001"

struct ISteamGameCoordinator001Vtbl
{
	void *SendMessage;
	MEMBER steam_bool_t (*IsMessageAvailable)(struct ISteamGameCoordinator *iface, uint32_t *msg_size);
	void *RetrieveMessage;
};

struct ISteamGameCoordinator *SteamGameCoordinator001(void);

#endif /* ISTEAMGAMECOORDINATOR001_H */
