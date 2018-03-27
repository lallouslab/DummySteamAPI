#ifndef ISTEAMNETWORKING_PRIV_H
#define ISTEAMNETWORKING_PRIV_H 1

#include "steam.h"

#include "ISteamNetworking.h"

struct ISteamNetworkingImpl
{
	struct ISteamNetworking base;
};

static inline struct ISteamNetworkingImpl *impl_from_ISteamNetworking(struct ISteamNetworking *iface) {
	return CONTAINER_OF(iface, struct ISteamNetworkingImpl, base);
}

steam_bool_t ISteamNetworking_ReadP2PPacket(struct ISteamNetworking *iface, void *pub_dest, uint32_t cub_dest, uint32_t *cub_msg_size, void /* CSteamID */ **steam_id_remote, int nchannels);
steam_bool_t ISteamNetworking_AllowP2PPacketRelay(struct ISteamNetworking *iface, steam_bool_t allow);

#endif /* ISTEAMNETWORKING_PRIV_H */
