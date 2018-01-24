#ifndef ISTEAMHTTP_H
#define ISTEAMHTTP_H 1

#define STEAMHTTP_INTERFACE_VERSION_PREFIX "STEAMHTTP_INTERFACE_VERSION"

struct ISteamHTTPImpl;

struct ISteamHTTPImpl *SteamHTTP_generic(const char *version);
extern struct ISteamHTTPImpl *SteamHTTP(void);

#endif /* ISTEAMHTTP_H */
