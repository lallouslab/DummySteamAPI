#ifndef ISTEAMGAMESERVER_PRIV_H
#define ISTEAMGAMESERVER_PRIV_H 1

#include "steam.h"
#include "utils.h"

#include "ISteamGameServer.h"

struct ISteamGameServerImpl
{
	struct ISteamGameServer base;
};

static inline struct ISteamGameServerImpl *impl_from_ISteamGameServer(struct ISteamGameServer *iface) {
	return CONTAINER_OF(iface, struct ISteamGameServerImpl, base);
}

#endif /* ISTEAMGAMESERVER_PRIV_H */
