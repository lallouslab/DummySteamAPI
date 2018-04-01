#ifndef ISTEAMMATCHMAKINGSERVERS_PRIV_H
#define ISTEAMMATCHMAKINGSERVERS_PRIV_H 1

#include "steam.h"

#include "ISteamMatchmakingServers.h"

struct ISteamMatchmakingServersImpl
{
	struct ISteamMatchmakingServers base;
};

static inline struct ISteamMatchmakingServersImpl *impl_from_ISteamMatchmakingServers(struct ISteamMatchmakingServers *iface) {
	return CONTAINER_OF(iface, struct ISteamMatchmakingServersImpl, base);
}

void ISteamMatchmakingServers_CancelQuery(struct ISteamMatchmakingServers *iface, steam_handle_server_list_request_t handle);

#endif /* ISTEAMMATCHMAKINGSERVERS_PRIV_H */
