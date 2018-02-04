#ifndef ISTEAMGAMESERVER_H
#define ISTEAMGAMESERVER_H 1

#define STEAMGAMESERVER_INTERFACE_VERSION_PREFIX "SteamGameServer"

struct ISteamGameServer
{
	const void *vtbl;
};

struct ISteamGameServer *SteamGameServer_generic(const char *version);
extern struct ISteamGameServer *SteamGameServer(void);

#endif /* ISTEAMGAMESERVER_H */
