#ifndef ISTEAMNETWORKING005_H
#define ISTEAMNETWORKING005_H 1

#include "steam.h"

#include "ISteamNetworking.h"

#define STEAMNETWORKING_INTERFACE_VERSION_005 "SteamNetworking005"

struct ISteamNetworking005Vtbl
{
	void *SendP2PPacket;
	void *IsP2PPacketAvailable;
	steam_bool_t (*ReadP2PPacket)(struct ISteamNetworking *iface, void *pub_dest, uint32_t cub_dest, uint32_t *cub_msg_size, void /* CSteamID */ **steam_id_remote, int nchannels);
	void *AcceptP2PSessionWithUser;
	void *CloseP2PSessionWithUser;
	void *CloseP2PChannelWithUser;
	void *GetP2PSessionState;
	steam_bool_t (*AllowP2PPacketRelay)(struct ISteamNetworking *iface, steam_bool_t allow);
	void *CreateListenSocket;
	void *CreateP2PConnectionSocket;
	void *CreateConnectionSocket;
	void *DestroySocket;
	void *DestroyListenSocket;
	void *SendDataOnSocket;
	void *IsDataAvailableOnSocket;
	void *RetrieveDataFromSocket;
	void *IsDataAvailable;
	void *RetrieveData;
	void *GetSocketInfo;
	void *GetListenSocketInfo;
	void *GetSocketConnectionType;
	void *GetMaxPacketSize;
};

static inline struct ISteamNetworking005Vtbl *get_ISteamNetworking005Vtbl_from_ISteamNetworking(struct ISteamNetworking *iface) {
	return (struct ISteamNetworking005Vtbl *)iface->vtbl;
}

struct ISteamNetworking *SteamNetworking005(void);

#endif /* ISTEAMNETWORKING005_H */
