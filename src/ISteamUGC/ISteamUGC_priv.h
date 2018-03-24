#ifndef ISTEAMUGC_PRIV_H
#define ISTEAMUGC_PRIV_H 1

#include "steam.h"
#include "utils.h"

#include "ISteamUGC.h"

struct ISteamUGCImpl
{
	struct ISteamUGC base;
};

static inline struct ISteamUGCImpl *impl_from_ISteamUGC(struct ISteamUGC *iface) {
	return CONTAINER_OF(iface, struct ISteamUGCImpl, base);
}

uint32_t ISteamUGC_GetNumSubscribedItems(struct ISteamUGC *iface);

#endif /* ISTEAMUGC_PRIV_H */
