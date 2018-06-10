#ifndef ISTEAMUSERSTATS_H
#define ISTEAMUSERSTATS_H 1

#include "steam.h"

#define STEAMUSERSTATS_INTERFACE_VERSION_PREFIX "STEAMUSERSTATS_INTERFACE_VERSION"

struct ISteamUserStats
{
	union
	{
		const void *ptr;
		const struct ISteamUserStats011Vtbl *v011;
	} vtbl;
};

typedef uint64_t steam_leaderboard_t;

enum steam_user_stats_leaderboard_display_type
{
	STEAM_USER_STATS_LEADERBOARD_DISPLAY_TYPE_NONE = 0u,
	STEAM_USER_STATS_LEADERBOARD_DISPLAY_TYPE_NUMERIC = 1u,
	STEAM_USER_STATS_LEADERBOARD_DISPLAY_TYPE_TIME_SEC = 2u,
	STEAM_USER_STATS_LEADERBOARD_DISPLAY_TYPE_TIME_MSEC = 3u
};

enum steam_user_stats_leaderboard_sort_method
{
	STEAM_USER_STATS_LEADERBOARD_SORT_METHOD_NONE = 0u,
	STEAM_USER_STATS_LEADERBOARD_SORT_METHOD_ASCENDING = 1u,
	STEAM_USER_STATS_LEADERBOARD_SORT_METHOD_DESCENDING = 2u
};

PACKED_STRUCT steam_callback_data_user_stats_user_stats_received
{
	union CGameID game_id;
	enum steam_result result;
	union CSteamID steam_id_user;
};

PACKED_STRUCT steam_callback_data_user_stats_leaderboard_find_result
{
	steam_leaderboard_t leaderboard;
	steam_bool_t found;
};

PACKED_STRUCT steam_callback_data_user_stats_global_stats_received
{
	union CGameID game_id;
	enum steam_result result;
};

struct ISteamUserStats *SteamUserStats_generic(const char *version);
void SteamUserStats_set_version(const char *version);
extern struct ISteamUserStats *SteamUserStats(void);

#endif /* ISTEAMUSERSTATS_H */
