#ifndef ISTEAMINVENTORY_PRIV_H
#define ISTEAMINVENTORY_PRIV_H 1

#include "steam.h"

#include "ISteamInventory.h"

struct ISteamInventoryImpl
{
	struct ISteamInventory base;
};

static inline struct ISteamInventoryImpl *impl_from_ISteamInventory(struct ISteamInventory *iface) {
	return CONTAINER_OF(iface, struct ISteamInventoryImpl, base);
}

#endif /* ISTEAMINVENTORY_PRIV_H */
