#ifndef ISTEAMNETWORKING_PRIV_H
#define ISTEAMNETWORKING_PRIV_H 1

#include "steam.h"

struct ISteamNetworkingImpl
{
	const void *iface;
};

steam_bool_t ISteamNetworking_ReadP2PPacket(struct ISteamNetworkingImpl *This, void *pub_dest, uint32_t cub_dest, uint32_t *cub_msg_size, void /* CSteamID */ **steam_id_remote, int nchannels);
steam_bool_t ISteamNetworking_AllowP2PPacketRelay(struct ISteamNetworkingImpl *This, steam_bool_t allow);

#endif /* ISTEAMNETWORKING_PRIV_H */
