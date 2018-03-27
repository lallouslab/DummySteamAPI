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

steam_bool_t ISteamGameServer_InitGameServer(struct ISteamGameServer *iface, uint32_t game_ip, uint16_t game_port, uint16_t query_port, enum steam_game_server_flag flags, steam_app_id_t app_id, const char *version);
void ISteamGameServer_SetProduct(struct ISteamGameServer *iface, const char *product);
void ISteamGameServer_SetGameDescription(struct ISteamGameServer *iface, const char *description);
void ISteamGameServer_SetModDir(struct ISteamGameServer *iface, const char *mod_dir);
void ISteamGameServer_SetDedicatedServer(struct ISteamGameServer *iface, steam_bool_t dedicated);
void ISteamGameServer_LogOnAnonymous(struct ISteamGameServer *iface);
void ISteamGameServer_LogOff(struct ISteamGameServer *iface);
void ISteamGameServer_SetMaxPlayerCount(struct ISteamGameServer *iface, int count);
void ISteamGameServer_SetBotPlayerCount(struct ISteamGameServer *iface, int count);
void ISteamGameServer_SetServerName(struct ISteamGameServer *iface, const char *name);
void ISteamGameServer_SetMapName(struct ISteamGameServer *iface, const char *name);
void ISteamGameServer_SetPasswordProtected(struct ISteamGameServer *iface, steam_bool_t protected);
void ISteamGameServer_SetKeyValue(struct ISteamGameServer *iface, const char *key, const char *value);
void ISteamGameServer_SetGameTags(struct ISteamGameServer *iface, const char *tags);
void ISteamGameServer_CreateUnauthenticatedUserConnection(union CSteamID *ret, struct ISteamGameServer *iface);
void ISteamGameServer_SendUserDisconnect(struct ISteamGameServer *iface, union CSteamID steam_id_user);
void ISteamGameServer_EnableHeartbeats(struct ISteamGameServer *iface, steam_bool_t enabled);

#endif /* ISTEAMGAMESERVER_PRIV_H */
