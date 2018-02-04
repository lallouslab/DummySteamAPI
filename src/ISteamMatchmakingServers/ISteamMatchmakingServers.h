#ifndef ISTEAMMATCHMAKINGSERVERS_H
#define ISTEAMMATCHMAKINGSERVERS_H 1

#define STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_PREFIX "SteamMatchMakingServers"

struct ISteamMatchmakingServers
{
	const void *vtbl;
};

struct ISteamMatchmakingServers *SteamMatchmakingServers_generic(const char *version);
void SteamMatchmakingServers_set_version(const char *version);
extern struct ISteamMatchmakingServers *SteamMatchmakingServers(void);

#endif /* ISTEAMMATCHMAKINGSERVERS_H */
