#ifndef ISTEAMGAMESERVER_H
#define ISTEAMGAMESERVER_H 1

#define STEAMGAMESERVER_INTERFACE_VERSION_PREFIX "SteamGameServer"

struct ISteamGameServer
{
	union
	{
		const void *ptr;
		const struct ISteamGameServer011Vtbl *v011;
		const struct ISteamGameServer012Vtbl *v012;
	} vtbl;
};

struct ISteamGameServer *SteamGameServer_generic(const char *version);
void SteamGameServer_set_version(const char *version);
extern struct ISteamGameServer *SteamGameServer(void);

#endif /* ISTEAMGAMESERVER_H */
