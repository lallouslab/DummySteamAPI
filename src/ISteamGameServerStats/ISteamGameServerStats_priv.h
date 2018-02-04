#ifndef ISTEAMGAMESERVERSTATS_PRIV_H
#define ISTEAMGAMESERVERSTATS_PRIV_H 1

#include "steam.h"
#include "utils.h"

#include "ISteamGameServerStats.h"

struct ISteamGameServerStatsImpl
{
	struct ISteamGameServerStats base;
};

static inline struct ISteamGameServerStatsImpl *impl_from_ISteamGameServerStats(struct ISteamGameServerStats *iface) {
	return CONTAINER_OF(iface, struct ISteamGameServerStatsImpl, base);
}

#endif /* ISTEAMGAMESERVERSTATS_PRIV_H */
