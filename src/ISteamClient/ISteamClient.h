#ifndef ISTEAMCLIENT_H
#define ISTEAMCLIENT_H 1

#define STEAMCLIENT_INTERFACE_VERSION_PREFIX "SteamClient"

struct ISteamClient
{
	const void *iface;
};

struct ISteamClient *SteamClient_generic(const char *version);
extern struct ISteamClient *SteamClient(void);

#endif /* ISTEAMCLIENT_H */
