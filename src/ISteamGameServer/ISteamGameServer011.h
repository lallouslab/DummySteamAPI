#ifndef ISTEAMGAMESERVER011_H
#define ISTEAMGAMESERVER011_H 1

#include "steam.h"

#include "ISteamGameServer.h"

#define STEAMGAMESERVER_INTERFACE_VERSION_011 "SteamGameServer011"

struct ISteamGameServer011Vtbl
{
	steam_bool_t (*InitGameServer)(struct ISteamGameServer *iface, uint32_t game_ip, uint16_t game_port, uint16_t query_port, enum steam_game_server_flag flags, steam_app_id_t app_id, const char *version);
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
	void (*CreateUnauthenticatedUserConnection)(union CSteamID *ret, struct ISteamGameServer *iface);
	void (*SendUserDisconnect)(struct ISteamGameServer *iface, union CSteamID steam_id_user);
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
	void (*EnableHeartbeats)(struct ISteamGameServer *iface, steam_bool_t enabled);
	void *SetHeartbeatInterval;
	void *ForceHeartbeat;
	void *AssociateWithClan;
	void *ComputeNewPlayerCompatibility;
};

struct ISteamGameServer *SteamGameServer011(void);

#endif /* ISTEAMGAMESERVER011_H */
