#ifndef ISTEAMUSERSTATS_PRIV_H
#define ISTEAMUSERSTATS_PRIV_H 1

#include "steam.h"

struct ISteamUserStatsImpl
{
	const void *iface;
};

steam_bool_t ISteamUserStats_RequestCurrentStats(struct ISteamUserStatsImpl *This);
steam_bool_t ISteamUserStats_GetStatI32(struct ISteamUserStatsImpl *This, const char *name, int32_t *data);
steam_bool_t ISteamUserStats_GetStatFloat(struct ISteamUserStatsImpl *This, const char *name, float *data);
steam_bool_t ISteamUserStats_SetStatI32(struct ISteamUserStatsImpl *This, const char *name, int32_t data);
steam_bool_t ISteamUserStats_SetStatFloat(struct ISteamUserStatsImpl *This, const char *name, float data);
steam_bool_t ISteamUserStats_UpdateAvgRateStat(struct ISteamUserStatsImpl *This, const char *name, float count_this_session, float session_length);
steam_bool_t ISteamUserStats_GetAchievement(struct ISteamUserStatsImpl *This, const char *name, steam_bool_t *achieved);
steam_bool_t ISteamUserStats_SetAchievement(struct ISteamUserStatsImpl *This, const char *name);
steam_bool_t ISteamUserStats_ClearAchievement(struct ISteamUserStatsImpl *This, const char *name);
steam_bool_t ISteamUserStats_GetAchievementAndUnlockTime(struct ISteamUserStatsImpl *This, const char *name, steam_bool_t *achieved, uint32_t *unlock_time);
steam_bool_t ISteamUserStats_StoreStats(struct ISteamUserStatsImpl *This);
steam_api_call_t ISteamUserStats_RequestUserStats(struct ISteamUserStatsImpl *This, union CSteamID steam_id_user);

#endif /* ISTEAMUSERSTATS_PRIV_H */
