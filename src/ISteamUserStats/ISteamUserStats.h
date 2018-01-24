#ifndef ISTEAMUSERSTATS_H
#define ISTEAMUSERSTATS_H 1

#define STEAMUSERSTATS_INTERFACE_VERSION_PREFIX "STEAMUSERSTATS_INTERFACE_VERSION"

struct ISteamUserStatsImpl;

struct ISteamUserStatsImpl *SteamUserStats_generic(const char *version);
extern struct ISteamUserStatsImpl *SteamUserStats(void);

#endif /* ISTEAMUSERSTATS_H */
