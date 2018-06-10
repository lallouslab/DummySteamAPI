#ifndef ISTEAMUGC_PRIV_H
#define ISTEAMUGC_PRIV_H 1

#include "steam.h"

#include "ISteamUGC.h"

struct ISteamUGCImpl
{
	struct ISteamUGC base;
};

static inline struct ISteamUGCImpl *impl_from_ISteamUGC(struct ISteamUGC *iface) {
	return CONTAINER_OF(iface, struct ISteamUGCImpl, base);
}

MEMBER steam_api_call_t ISteamUGC_SendQueryUGCRequest(struct ISteamUGC *iface, steam_ugc_query_handle_t handle);
MEMBER steam_bool_t ISteamUGC_SetReturnChildren(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_children);
MEMBER uint32_t ISteamUGC_GetNumSubscribedItems(struct ISteamUGC *iface);

#endif /* ISTEAMUGC_PRIV_H */
