#ifndef ISTEAMUSER004_H
#define ISTEAMUSER004_H 1

#include "steam.h"

#include "ISteamUser.h"

#define STEAMUSER_INTERFACE_VERSION_004 "SteamUser004"

struct ISteamUser004Vtbl
{
	MEMBER steam_user_t (*GetHSteamUser)(struct ISteamUser *iface);
	void *LogOn;
	void *LogOff;
	MEMBER steam_bool_t (*BLoggedOn)(struct ISteamUser *iface);
	void *GetLogonState;
	void *BConnected;
	MEMBER void (*GetSteamID)(union CSteamID *ret, struct ISteamUser *iface);
	void *IsVACBanned;
	void *RequireShowVACBannedMessage;
	void *AcknowledgeVACBanning;
	void *NClientGameIDAdd;
	void *RemoveClientGame;
	void *SetClientGameServer;
	void *SetSteam2Ticket;
	void *AddServerNetAddress;
	void *SetEmail;
	void *GetSteamGameConnectToken;
	void *SetRegistryString;
	void *GetRegistryString;
	void *SetRegistryInt;
	void *GetRegistryInt;
	MEMBER int (*InitiateGameConnection)(struct ISteamUser *iface, void *auth_blob, int auth_blob_size, union CSteamID steam_id_game_server, steam_app_id_t app_id, uint32_t server_ip, uint16_t server_port, steam_bool_t secure);
	MEMBER void (*TerminateGameConnection)(struct ISteamUser *iface, uint32_t server_ip, uint16_t server_port);
	void *SetSelfAsPrimaryChatDestination;
	void *IsPrimaryChatDestination;
	void *RequestLegacyCDKey;
};

struct ISteamUser *SteamUser004(void);

#endif /* ISTEAMUSER004_H */
