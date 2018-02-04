#ifndef ISTEAMUSERSTATS_H
#define ISTEAMUSERSTATS_H 1

#define STEAMUSERSTATS_INTERFACE_VERSION_PREFIX "STEAMUSERSTATS_INTERFACE_VERSION"

struct ISteamUserStats
{
	const void *vtbl;
};

struct ISteamUserStats *SteamUserStats_generic(const char *version);
void SteamUserStats_set_version(const char *version);
extern struct ISteamUserStats *SteamUserStats(void);

#endif /* ISTEAMUSERSTATS_H */
