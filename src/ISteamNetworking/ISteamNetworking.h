#ifndef ISTEAMNETWORKING_H
#define ISTEAMNETWORKING_H 1

#define STEAMNETWORKING_INTERFACE_VERSION_PREFIX "SteamNetworking"

struct ISteamNetworking
{
	union
	{
		const void *ptr;
		const struct ISteamNetworking001Vtbl *v001;
		const struct ISteamNetworking005Vtbl *v005;
	} vtbl;
};

struct ISteamNetworking *SteamNetworking_generic(const char *version);
void SteamNetworking_set_version(const char *version);
extern struct ISteamNetworking *SteamNetworking(void);

#endif /* ISTEAMNETWORKING_H */
