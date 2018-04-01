#ifndef ISTEAMNETWORKING005_H
#define ISTEAMNETWORKING005_H 1

#include "steam.h"

#include "ISteamNetworking.h"

#define STEAMNETWORKING_INTERFACE_VERSION_005 "SteamNetworking005"

struct ISteamNetworking005Vtbl
{
	void *SendP2PPacket;
	MEMBER steam_bool_t (*IsP2PPacketAvailable)(struct ISteamNetworking *iface, uint32_t *msg_size, int channel);
	MEMBER steam_bool_t (*ReadP2PPacket)(struct ISteamNetworking *iface, void *dest, uint32_t dest_size, uint32_t *msg_size, void /* CSteamID */ **steam_id_remote, int channel);
	void *AcceptP2PSessionWithUser;
	void *CloseP2PSessionWithUser;
	void *CloseP2PChannelWithUser;
	void *GetP2PSessionState;
	MEMBER steam_bool_t (*AllowP2PPacketRelay)(struct ISteamNetworking *iface, steam_bool_t allow);
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

struct ISteamNetworking *SteamNetworking005(void);

#endif /* ISTEAMNETWORKING005_H */
