#ifndef ISTEAMUSERSTATS_PRIV_H
#define ISTEAMUSERSTATS_PRIV_H 1

#include "CCallback.h"
#include "steam.h"

#include "ISteamUserStats.h"

struct ISteamUserStatsImplCommon
{
	steam_bool_t is_init : 1;
	const char *default_version;
	struct CCallResult request_current_stats_call_result;
};

struct ISteamUserStatsImpl
{
	struct ISteamUserStats base;
	struct ISteamUserStatsImplCommon *common;
};

static inline struct ISteamUserStatsImpl *impl_from_ISteamUserStats(struct ISteamUserStats *iface) {
	return CONTAINER_OF(iface, struct ISteamUserStatsImpl, base);
}

MEMBER void ISteamUserStats_ctor(struct ISteamUserStats *iface);
MEMBER steam_bool_t ISteamUserStats_RequestCurrentStats(struct ISteamUserStats *iface);
MEMBER steam_bool_t ISteamUserStats_GetStatI32(struct ISteamUserStats *iface, const char *name, int32_t *data);
MEMBER steam_bool_t ISteamUserStats_GetStatFloat(struct ISteamUserStats *iface, const char *name, float *data);
MEMBER steam_bool_t ISteamUserStats_SetStatI32(struct ISteamUserStats *iface, const char *name, int32_t data);
MEMBER steam_bool_t ISteamUserStats_SetStatFloat(struct ISteamUserStats *iface, const char *name, float data);
MEMBER steam_bool_t ISteamUserStats_UpdateAvgRateStat(struct ISteamUserStats *iface, const char *name, float count_this_session, float session_length);
MEMBER steam_bool_t ISteamUserStats_GetAchievement(struct ISteamUserStats *iface, const char *name, steam_bool_t *achieved);
MEMBER steam_bool_t ISteamUserStats_SetAchievement(struct ISteamUserStats *iface, const char *name);
MEMBER steam_bool_t ISteamUserStats_ClearAchievement(struct ISteamUserStats *iface, const char *name);
MEMBER steam_bool_t ISteamUserStats_GetAchievementAndUnlockTime(struct ISteamUserStats *iface, const char *name, steam_bool_t *achieved, uint32_t *unlock_time);
MEMBER steam_bool_t ISteamUserStats_StoreStats(struct ISteamUserStats *iface);
MEMBER int ISteamUserStats_GetAchievementIcon(struct ISteamUserStats *iface, const char *name);
MEMBER const char *ISteamUserStats_GetAchievementDisplayAttribute(struct ISteamUserStats *iface, const char *name, const char *key);
MEMBER steam_bool_t ISteamUserStats_IndicateAchievementProgress(struct ISteamUserStats *iface, const char *name, uint32_t cur_progress, uint32_t max_progress);
MEMBER steam_api_call_t ISteamUserStats_RequestUserStats(struct ISteamUserStats *iface, union CSteamID steam_id_user);
MEMBER steam_api_call_t ISteamUserStats_FindOrCreateLeaderboard(struct ISteamUserStats *iface, const char *name, enum steam_user_stats_leaderboard_sort_method sort_method, enum steam_user_stats_leaderboard_display_type display_type);
MEMBER steam_bool_t ISteamUserStats_GetGlobalStatI64(struct ISteamUserStats *iface, const char *name, int64_t *data);
MEMBER steam_bool_t ISteamUserStats_GetGlobalStatDouble(struct ISteamUserStats *iface, const char *name, double *data);

#endif /* ISTEAMUSERSTATS_PRIV_H */
