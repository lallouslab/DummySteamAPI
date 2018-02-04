#ifndef ISTEAMNETWORKING_H
#define ISTEAMNETWORKING_H 1

#define STEAMNETWORKING_INTERFACE_VERSION_PREFIX "SteamNetworking"

struct ISteamNetworking
{
	const void *vtbl;
};

struct ISteamNetworking *SteamNetworking_generic(const char *version);
void SteamNetworking_set_version(const char *version);
extern struct ISteamNetworking *SteamNetworking(void);

#endif /* ISTEAMNETWORKING_H */
