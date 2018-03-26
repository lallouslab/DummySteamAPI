#ifndef ISTEAMUSER004_H
#define ISTEAMUSER004_H 1

#include "steam.h"

#include "ISteamUser.h"

#define STEAMUSER_INTERFACE_VERSION_004 "SteamUser004"

struct ISteamUser004Vtbl
{
	steam_user_t (*GetHSteamUser)(struct ISteamUser *iface);
	void *LogOn;
	void *LogOff;
	steam_bool_t (*BLoggedOn)(struct ISteamUser *iface);
	void *GetLogonState;
	void *BConnected;
	void (*GetSteamID)(union CSteamID *ret, struct ISteamUser *iface);
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
	void *InitiateGameConnection;
	void *TerminateGameConnection;
	void *SetSelfAsPrimaryChatDestination;
	void *IsPrimaryChatDestination;
	void *RequestLegacyCDKey;
};

struct ISteamUser *SteamUser004(void);

#endif /* ISTEAMUSER004_H */
