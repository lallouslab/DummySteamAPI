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
	MEMBER steam_bool_t (*BLoggedOn)(struct ISteamGameServer *iface);
	MEMBER steam_bool_t (*BSecure)(struct ISteamGameServer *iface);
	DSA_PFN_MEMBER_RETURN_STRUCT0(union CSteamID, ret, GetSteamID, struct ISteamGameServer *iface);
	void *WasRestartRequested;
	MEMBER void (*SetMaxPlayerCount)(struct ISteamGameServer *iface, int count);
	MEMBER void (*SetBotPlayerCount)(struct ISteamGameServer *iface, int count);
	MEMBER void (*SetServerName)(struct ISteamGameServer *iface, const char *name);
	MEMBER void (*SetMapName)(struct ISteamGameServer *iface, const char *name);
	MEMBER void (*SetPasswordProtected)(struct ISteamGameServer *iface, steam_bool_t protected);
	MEMBER void (*SetSpectatorPort)(struct ISteamGameServer *iface, uint16_t port);
	void *SetSpectatorServerName;
	void *ClearAllKeyValues;
	MEMBER void (*SetKeyValue)(struct ISteamGameServer *iface, const char *key, const char *value);
	MEMBER void (*SetGameTags)(struct ISteamGameServer *iface, const char *tags);
	void *SetGameData;
	void *SetRegion;
	MEMBER steam_bool_t (*SendUserConnectAndAuthenticate)(struct ISteamGameServer *iface, uint32_t client_ip, const void *auth_blob, uint32_t auth_blob_size, union CSteamID *steam_id_user);
	DSA_PFN_MEMBER_RETURN_STRUCT0(union CSteamID, ret, CreateUnauthenticatedUserConnection, struct ISteamGameServer *iface);
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
	MEMBER steam_bool_t (*HandleIncomingPacket)(struct ISteamGameServer *iface, const void *data, int data_size, uint32_t src_ip, uint16_t src_port);
	void *GetNextOutgoingPacket;
	MEMBER void (*EnableHeartbeats)(struct ISteamGameServer *iface, steam_bool_t enabled);
	void *SetHeartbeatInterval;
	void *ForceHeartbeat;
	void *AssociateWithClan;
	void *ComputeNewPlayerCompatibility;
};

#define ISteamGameServer011_GetSteamID(iface, ret) DSA_CALL_MEMBER_RETURN_STRUCT0(iface->vtbl.v011->GetSteamID, ret, iface)
#define ISteamGameServer011_CreateUnauthenticatedUserConnection(iface, ret) DSA_CALL_MEMBER_RETURN_STRUCT0(iface->vtbl.v011->CreateUnauthenticatedUserConnection, ret, iface)

struct ISteamGameServer *SteamGameServer011(void);

#endif /* ISTEAMGAMESERVER011_H */
