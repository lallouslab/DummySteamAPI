#ifndef ISTEAMGAMESERVERSTATS_H
#define ISTEAMGAMESERVERSTATS_H 1

#define STEAMGAMESERVERSTATS_INTERFACE_VERSION_PREFIX "SteamGameServerStats"

struct ISteamGameServerStatsImpl;

struct ISteamGameServerStatsImpl *SteamGameServerStats_generic(const char *version);
extern struct ISteamGameServerStatsImpl *SteamGameServerStats(void);

#endif /* ISTEAMGAMESERVERSTATS_H */
