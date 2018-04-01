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

MEMBER steam_bool_t ISteamNetworking_IsP2PPacketAvailable(struct ISteamNetworking *iface, uint32_t *msg_size, int channel);
MEMBER steam_bool_t ISteamNetworking_ReadP2PPacket(struct ISteamNetworking *iface, void *dest, uint32_t dest_size, uint32_t *msg_size, void /* CSteamID */ **steam_id_remote, int channel);
MEMBER steam_bool_t ISteamNetworking_AllowP2PPacketRelay(struct ISteamNetworking *iface, steam_bool_t allow);

#endif /* ISTEAMNETWORKING_PRIV_H */
