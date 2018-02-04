#ifndef ISTEAMMATCHMAKING_H
#define ISTEAMMATCHMAKING_H 1

#define STEAMMATCHMAKING_INTERFACE_VERSION_PREFIX "SteamMatchMaking"

struct ISteamMatchmaking
{
	const void *vtbl;
};

struct ISteamMatchmaking *SteamMatchmaking_generic(const char *version);
extern struct ISteamMatchmaking *SteamMatchmaking(void);

#endif /* ISTEAMMATCHMAKING_H */
