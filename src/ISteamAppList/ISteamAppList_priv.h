#ifndef ISTEAMAPPLIST_PRIV_H
#define ISTEAMAPPLIST_PRIV_H 1

#include "steam.h"

#include "ISteamAppList.h"

struct ISteamAppListImpl
{
	struct ISteamAppList base;
};

static inline struct ISteamAppListImpl *impl_from_ISteamAppList(struct ISteamAppList *iface) {
	return CONTAINER_OF(iface, struct ISteamAppListImpl, base);
}

#endif /* ISTEAMAPPLIST_PRIV_H */
