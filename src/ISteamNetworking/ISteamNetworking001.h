#ifndef ISTEAMNETWORKING001_H
#define ISTEAMNETWORKING001_H 1

#include "steam.h"

#include "ISteamNetworking.h"

#define STEAMNETWORKING_INTERFACE_VERSION_001 "SteamNetworking001"

struct ISteamNetworking001
{
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
};

struct ISteamNetworkingImpl *SteamNetworking001(void);

#endif /* ISTEAMNETWORKING001_H */
