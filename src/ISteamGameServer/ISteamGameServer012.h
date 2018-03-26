#ifndef ISTEAMGAMESERVER012_H
#define ISTEAMGAMESERVER012_H 1

#include "steam.h"

#include "ISteamGameServer.h"

#define STEAMGAMESERVER_INTERFACE_VERSION_012 "SteamGameServer012"

struct ISteamGameServer012Vtbl
{
	void *InitGameServer;
	void *SetProduct;
	void *SetGameDescription;
	void *SetModDir;
	void *SetDedicatedServer;
	void *LogOn;
	void *LogOnAnonymous;
	void *LogOff;
	void *BLoggedOn;
	void *BSecure;
	void *GetSteamID;
	void *WasRestartRequested;
	void *SetMaxPlayerCount;
	void *SetBotPlayerCount;
	void *SetServerName;
	void *SetMapName;
	void *SetPasswordProtected;
	void *SetSpectatorPort;
	void *SetSpectatorServerName;
	void *ClearAllKeyValues;
	void *SetKeyValue;
	void *SetGameTags;
	void *SetGameData;
	void *SetRegion;
	void *SendUserConnectAndAuthenticate;
	void *CreateUnauthenticatedUserConnection;
	void *SendUserDisconnect;
	void *BUpdateUserData;
	void *GetAuthSessionTicket;
	void *BeginAuthSession;
	void *EndAuthSession;
	void *CancelAuthTicket;
	void *UserHasLicenseForApp;
	void *RequestUserGroupStatus;
	void *GetGameplayStats;
	void *GetServerReputation;
	void *GetPublicIP;
	void *HandleIncomingPacket;
	void *GetNextOutgoingPacket;
	void *EnableHeartbeats;
	void *SetHeartbeatInterval;
	void *ForceHeartbeat;
	void *AssociateWithClan;
	void *ComputeNewPlayerCompatibility;
};

struct ISteamGameServer *SteamGameServer012(void);

#endif /* ISTEAMGAMESERVER012_H */
