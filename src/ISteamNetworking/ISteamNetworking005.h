#ifndef ISTEAMNETWORKING005_H
#define ISTEAMNETWORKING005_H 1

#include "steam.h"

#include "ISteamNetworking.h"

#define STEAMNETWORKING_INTERFACE_VERSION_005 "SteamNetworking005"

struct ISteamNetworking005
{
	void *SendP2PPacket;
	void *IsP2PPacketAvailable;
	steam_bool_t (*ReadP2PPacket)(struct ISteamNetworkingImpl *This, void *pub_dest, uint32_t cub_dest, uint32_t *cub_msg_size, void /* CSteamID */ **steam_id_remote, int nchannels);
	void *AcceptP2PSessionWithUser;
	void *CloseP2PSessionWithUser;
	void *CloseP2PChannelWithUser;
	void *GetP2PSessionState;
	steam_bool_t (*AllowP2PPacketRelay)(struct ISteamNetworkingImpl *This, steam_bool_t allow);
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

struct ISteamNetworkingImpl *SteamNetworking005(void);

#endif /* ISTEAMNETWORKING005_H */
