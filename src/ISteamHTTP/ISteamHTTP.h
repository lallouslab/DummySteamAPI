#ifndef ISTEAMHTTP_H
#define ISTEAMHTTP_H 1

#define STEAMHTTP_INTERFACE_VERSION_PREFIX "STEAMHTTP_INTERFACE_VERSION"

struct ISteamHTTP
{
	union
	{
		const void *ptr;
		const struct ISteamHTTP001Vtbl *v001;
		const struct ISteamHTTP002Vtbl *v002;
	} vtbl;
};

struct ISteamHTTP *SteamHTTP_generic(const char *version);
void SteamHTTP_set_version(const char *version);
extern struct ISteamHTTP *SteamHTTP(void);

#endif /* ISTEAMHTTP_H */
