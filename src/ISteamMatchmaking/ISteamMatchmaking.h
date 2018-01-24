#ifndef ISTEAMMATCHMAKING_H
#define ISTEAMMATCHMAKING_H 1

#define STEAMMATCHMAKING_INTERFACE_VERSION_PREFIX "SteamMatchMaking"

struct ISteamMatchmakingImpl;

struct ISteamMatchmakingImpl *SteamMatchmaking_generic(const char *version);
extern struct ISteamMatchmakingImpl *SteamMatchmaking(void);

#endif /* ISTEAMMATCHMAKING_H */
