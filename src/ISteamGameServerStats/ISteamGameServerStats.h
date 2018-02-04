#ifndef ISTEAMGAMESERVERSTATS_H
#define ISTEAMGAMESERVERSTATS_H 1

#define STEAMGAMESERVERSTATS_INTERFACE_VERSION_PREFIX "SteamGameServerStats"

struct ISteamGameServerStats
{
	const void *vtbl;
};

struct ISteamGameServerStats *SteamGameServerStats_generic(const char *version);
void SteamGameServerStats_set_version(const char *version);
extern struct ISteamGameServerStats *SteamGameServerStats(void);

#endif /* ISTEAMGAMESERVERSTATS_H */
