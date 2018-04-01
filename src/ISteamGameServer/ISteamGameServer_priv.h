#ifndef ISTEAMGAMESERVER_PRIV_H
#define ISTEAMGAMESERVER_PRIV_H 1

#include "steam.h"

#include "ISteamGameServer.h"

struct ISteamGameServerImpl
{
	struct ISteamGameServer base;
};

static inline struct ISteamGameServerImpl *impl_from_ISteamGameServer(struct ISteamGameServer *iface) {
	return CONTAINER_OF(iface, struct ISteamGameServerImpl, base);
}

MEMBER steam_bool_t ISteamGameServer_InitGameServer(struct ISteamGameServer *iface, uint32_t game_ip, uint16_t game_port, uint16_t query_port, enum steam_game_server_flag flags, steam_app_id_t app_id, const char *version);
MEMBER void ISteamGameServer_SetProduct(struct ISteamGameServer *iface, const char *product);
MEMBER void ISteamGameServer_SetGameDescription(struct ISteamGameServer *iface, const char *description);
MEMBER void ISteamGameServer_SetModDir(struct ISteamGameServer *iface, const char *mod_dir);
MEMBER void ISteamGameServer_SetDedicatedServer(struct ISteamGameServer *iface, steam_bool_t dedicated);
MEMBER void ISteamGameServer_LogOnAnonymous(struct ISteamGameServer *iface);
MEMBER void ISteamGameServer_LogOff(struct ISteamGameServer *iface);
MEMBER steam_bool_t ISteamGameServer_BLoggedOn(struct ISteamGameServer *iface);
MEMBER steam_bool_t ISteamGameServer_BSecure(struct ISteamGameServer *iface);
MEMBER union CSteamID ISteamGameServer_GetSteamID(struct ISteamGameServer *iface);
MEMBER void ISteamGameServer_SetMaxPlayerCount(struct ISteamGameServer *iface, int count);
MEMBER void ISteamGameServer_SetBotPlayerCount(struct ISteamGameServer *iface, int count);
MEMBER void ISteamGameServer_SetServerName(struct ISteamGameServer *iface, const char *name);
MEMBER void ISteamGameServer_SetMapName(struct ISteamGameServer *iface, const char *name);
MEMBER void ISteamGameServer_SetPasswordProtected(struct ISteamGameServer *iface, steam_bool_t protected);
MEMBER void ISteamGameServer_SetSpectatorPort(struct ISteamGameServer *iface, uint16_t port);
MEMBER void ISteamGameServer_SetKeyValue(struct ISteamGameServer *iface, const char *key, const char *value);
MEMBER void ISteamGameServer_SetGameTags(struct ISteamGameServer *iface, const char *tags);
MEMBER void ISteamGameServer_CreateUnauthenticatedUserConnection(union CSteamID *ret, struct ISteamGameServer *iface);
MEMBER void ISteamGameServer_SendUserDisconnect(struct ISteamGameServer *iface, union CSteamID steam_id_user);
MEMBER void ISteamGameServer_EnableHeartbeats(struct ISteamGameServer *iface, steam_bool_t enabled);

#endif /* ISTEAMGAMESERVER_PRIV_H */
