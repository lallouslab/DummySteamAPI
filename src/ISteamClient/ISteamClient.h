#ifndef ISTEAMCLIENT_H
#define ISTEAMCLIENT_H 1

#define STEAMCLIENT_INTERFACE_VERSION_PREFIX "SteamClient"

struct ISteamClient
{
	union
	{
		const void *ptr;
		const struct ISteamClient006Vtbl *v006;
		const struct ISteamClient012Vtbl *v012;
		const struct ISteamClient014Vtbl *v014;
		const struct ISteamClient016Vtbl *v016;
		const struct ISteamClient017Vtbl *v017;
	} vtbl;
};

struct ISteamClient *SteamClient_generic(const char *version);
void SteamClient_set_version(const char *version);
extern struct ISteamClient *SteamClient(void);

#endif /* ISTEAMCLIENT_H */
