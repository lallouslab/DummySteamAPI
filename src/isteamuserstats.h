#ifndef ISTEAMUSERSTATS_H
#define ISTEAMUSERSTATS_H

#include "steam.h"

struct ISteamUserStatsImpl;

struct ISteamUserStats
{
	steam_bool_t (*RequestCurrentStats)(struct ISteamUserStatsImpl *This);
	steam_bool_t (*GetStatI32)(struct ISteamUserStatsImpl *This, const char *name, int32_t *data);
	steam_bool_t (*GetStatFloat)(struct ISteamUserStatsImpl *This, const char *name, float *data);
	steam_bool_t (*SetStatI32)(struct ISteamUserStatsImpl *This, const char *name, int32_t data);
	steam_bool_t (*SetStatFloat)(struct ISteamUserStatsImpl *This, const char *name, float data);
	steam_bool_t (*UpdateAvgRateStat)(struct ISteamUserStatsImpl *This, const char *name, float count_this_session, float session_length);
	steam_bool_t (*GetAchievement)(struct ISteamUserStatsImpl *This, const char *name, steam_bool_t *achieved);
	steam_bool_t (*SetAchievement)(struct ISteamUserStatsImpl *This, const char *name);
	steam_bool_t (*ClearAchievement)(struct ISteamUserStatsImpl *This, const char *name);
	steam_bool_t (*GetAchievementAndUnlockTime)(struct ISteamUserStatsImpl *This, const char *name, steam_bool_t *achieved, uint32_t *unlock_time);
	steam_bool_t (*StoreStats)(struct ISteamUserStatsImpl *This);
};

struct ISteamUserStatsImpl *SteamUserStats(void);

#endif /* ISTEAMUSERSTATS_H */
