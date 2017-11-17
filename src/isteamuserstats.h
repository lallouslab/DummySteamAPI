#ifndef ISTEAMUSERSTATS_H
#define ISTEAMUSERSTATS_H

#include "steam.h"

struct ISteamUserStatsImpl;

struct ISteamUserStats
{
	int (*RequestCurrentStats)(struct ISteamUserStatsImpl *This);
	int (*GetStatI32)(struct ISteamUserStatsImpl *This, const char *name, int32_t *data);
	int (*GetStatFloat)(struct ISteamUserStatsImpl *This, const char *name, float *data);
	int (*SetStatI32)(struct ISteamUserStatsImpl *This, const char *name, int32_t data);
	int (*SetStatFloat)(struct ISteamUserStatsImpl *This, const char *name, float data);
	int (*UpdateAvgRateStat)(struct ISteamUserStatsImpl *This, const char *name, float count_this_session, float session_length);
	int (*GetAchievement)(struct ISteamUserStatsImpl *This, const char *name, int *achieved);
	int (*SetAchievement)(struct ISteamUserStatsImpl *This, const char *name);
	int (*ClearAchievement)(struct ISteamUserStatsImpl *This, const char *name);
	int (*GetAchievementAndUnlockTime)(struct ISteamUserStatsImpl *This, const char *name, int *achieved, uint32_t *unlock_time);
	int (*StoreStats)(struct ISteamUserStatsImpl *This);
};

struct ISteamUserStatsImpl *SteamUserStats(void);

#endif /* ISTEAMUSERSTATS_H */
