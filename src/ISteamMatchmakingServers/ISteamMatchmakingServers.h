#ifndef ISTEAMMATCHMAKINGSERVERS_H
#define ISTEAMMATCHMAKINGSERVERS_H 1

#define STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_PREFIX "SteamMatchMakingServers"

struct ISteamMatchmakingServersImpl;

struct ISteamMatchmakingServersImpl *SteamMatchmakingServers_generic(const char *version);
extern struct ISteamMatchmakingServersImpl *SteamMatchmakingServers(void);

#endif /* ISTEAMMATCHMAKINGSERVERS_H */
