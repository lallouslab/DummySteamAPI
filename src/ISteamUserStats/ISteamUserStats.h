#ifndef ISTEAMUSERSTATS_H
#define ISTEAMUSERSTATS_H 1

#include "steam.h"
#include "utils.h"

#define STEAMUSERSTATS_INTERFACE_VERSION_PREFIX "STEAMUSERSTATS_INTERFACE_VERSION"

struct ISteamUserStats
{
	union
	{
		const void *ptr;
		const struct ISteamUserStats011Vtbl *v011;
	} vtbl;
};

PACKED_STRUCT steam_callback_data_user_stats_user_stats_received
{
	uint64_t game_id;
	enum steam_result result;
	union CSteamID steam_id_user;
};

struct ISteamUserStats *SteamUserStats_generic(const char *version);
void SteamUserStats_set_version(const char *version);
extern struct ISteamUserStats *SteamUserStats(void);

#endif /* ISTEAMUSERSTATS_H */
