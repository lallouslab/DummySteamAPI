#ifndef ISTEAMGAMESERVER011_H
#define ISTEAMGAMESERVER011_H 1

#include "steam.h"

#include "ISteamGameServer.h"

#define STEAMGAMESERVER_INTERFACE_VERSION_011 "SteamGameServer011"

struct ISteamGameServer011Vtbl
{
	MEMBER steam_bool_t (*InitGameServer)(struct ISteamGameServer *iface, uint32_t game_ip, uint16_t game_port, uint16_t query_port, enum steam_game_server_flag flags, steam_app_id_t app_id, const char *version);
	MEMBER void (*SetProduct)(struct ISteamGameServer *iface, const char *product);
	MEMBER void (*SetGameDescription)(struct ISteamGameServer *iface, const char *description);
	MEMBER void (*SetModDir)(struct ISteamGameServer *iface, const char *mod_dir);
	MEMBER void (*SetDedicatedServer)(struct ISteamGameServer *iface, steam_bool_t dedicated);
	void *LogOn;
	MEMBER void (*LogOnAnonymous)(struct ISteamGameServer *iface);
	MEMBER void (*LogOff)(struct ISteamGameServer *iface);
	void *BLoggedOn;
	void *BSecure;
	void *GetSteamID;
	void *WasRestartRequested;
	MEMBER void (*SetMaxPlayerCount)(struct ISteamGameServer *iface, int count);
	MEMBER void (*SetBotPlayerCount)(struct ISteamGameServer *iface, int count);
	MEMBER void (*SetServerName)(struct ISteamGameServer *iface, const char *name);
	MEMBER void (*SetMapName)(struct ISteamGameServer *iface, const char *name);
	MEMBER void (*SetPasswordProtected)(struct ISteamGameServer *iface, steam_bool_t protected);
	void *SetSpectatorPort;
	void *SetSpectatorServerName;
	void *ClearAllKeyValues;
	MEMBER void (*SetKeyValue)(struct ISteamGameServer *iface, const char *key, const char *value);
	MEMBER void (*SetGameTags)(struct ISteamGameServer *iface, const char *tags);
	void *SetGameData;
	void *SetRegion;
	void *SendUserConnectAndAuthenticate;
	MEMBER void (*CreateUnauthenticatedUserConnection)(union CSteamID *ret, struct ISteamGameServer *iface);
	MEMBER void (*SendUserDisconnect)(struct ISteamGameServer *iface, union CSteamID steam_id_user);
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
	MEMBER void (*EnableHeartbeats)(struct ISteamGameServer *iface, steam_bool_t enabled);
	void *SetHeartbeatInterval;
	void *ForceHeartbeat;
	void *AssociateWithClan;
	void *ComputeNewPlayerCompatibility;
};

struct ISteamGameServer *SteamGameServer011(void);

#endif /* ISTEAMGAMESERVER011_H */
