#ifndef ISTEAMHTTP_H
#define ISTEAMHTTP_H 1

#define STEAMHTTP_INTERFACE_VERSION_PREFIX "STEAMHTTP_INTERFACE_VERSION"

struct ISteamHTTP
{
	const void *vtbl;
};

struct ISteamHTTP *SteamHTTP_generic(const char *version);
extern struct ISteamHTTP *SteamHTTP(void);

#endif /* ISTEAMHTTP_H */
