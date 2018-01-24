#ifndef ISTEAMGAMESERVER_H
#define ISTEAMGAMESERVER_H 1

#define STEAMGAMESERVER_INTERFACE_VERSION_PREFIX "SteamGameServer"

struct ISteamGameServerImpl;

struct ISteamGameServerImpl *SteamGameServer_generic(const char *version);
extern struct ISteamGameServerImpl *SteamGameServer(void);

#endif /* ISTEAMGAMESERVER_H */
