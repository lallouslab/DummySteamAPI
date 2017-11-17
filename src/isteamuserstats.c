#include <inttypes.h>

#include "isteamuserstats.h"
#include "utils.h"

struct ISteamUserStatsImpl
{
	const struct ISteamUserStats *iface;
};

static int ISteamUserStats_RequestCurrentStats(struct ISteamUserStatsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return 0;
}

static int ISteamUserStats_GetStatI32(struct ISteamUserStatsImpl *This, const char *name, int32_t *data)
{
	log_enter_notimpl("(This = %p, name = %s, data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	return 1;
}

static int ISteamUserStats_GetStatFloat(struct ISteamUserStatsImpl *This, const char *name, float *data)
{
	log_enter_notimpl("(This = %p, name = %s, data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	return 1;
}

static int ISteamUserStats_SetStatI32(struct ISteamUserStatsImpl *This, const char *name, int32_t data)
{
	log_enter_notimpl("(This = %p, name = %s, data = %" PRIi32 ")", VOIDPTR(This), debug_str(name), data);

	return 1;
}

static int ISteamUserStats_SetStatFloat(struct ISteamUserStatsImpl *This, const char *name, float data)
{
	log_enter_notimpl("(This = %p, name = %s, data = %f)", VOIDPTR(This), debug_str(name), data);

	return 1;
}

static int ISteamUserStats_UpdateAvgRateStat(struct ISteamUserStatsImpl *This, const char *name, float count_this_session, float session_length)
{
	log_enter_notimpl("(This = %p, name = %s, count_this_session = %f, session_length = %f)", VOIDPTR(This), debug_str(name), count_this_session, session_length);

	return 1;
}

static int ISteamUserStats_GetAchievement(struct ISteamUserStatsImpl *This, const char *name, int *achieved)
{
	log_enter_notimpl("(This = %p, name = %s, data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(achieved));

	return 1;
}

static int ISteamUserStats_SetAchievement(struct ISteamUserStatsImpl *This, const char *name)
{
	log_enter_notimpl("(This = %p, name = %s)", VOIDPTR(This), debug_str(name));

	return 1;
}

static int ISteamUserStats_ClearAchievement(struct ISteamUserStatsImpl *This, const char *name)
{
	log_enter_notimpl("(This = %p, name = %s)", VOIDPTR(This), debug_str(name));

	return 1;
}

static int ISteamUserStats_GetAchievementAndUnlockTime(struct ISteamUserStatsImpl *This, const char *name, int *achieved, uint32_t *unlock_time)
{
	log_enter_notimpl("(This = %p, name = %s, achieved = %p, unlock_time = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(achieved), VOIDPTR(unlock_time));

	return 1;
}

static int ISteamUserStats_StoreStats(struct ISteamUserStatsImpl *This)
{
	log_enter_notimpl("(This = %p)", VOIDPTR(This));

	return 0;
}

static const struct ISteamUserStats ISteamUserStats_vtbl = {
	ISteamUserStats_RequestCurrentStats,
	ISteamUserStats_GetStatI32,
	ISteamUserStats_GetStatFloat,
	ISteamUserStats_SetStatI32,
	ISteamUserStats_SetStatFloat,
	ISteamUserStats_UpdateAvgRateStat,
	ISteamUserStats_GetAchievement,
	ISteamUserStats_SetAchievement,
	ISteamUserStats_ClearAchievement,
	ISteamUserStats_GetAchievementAndUnlockTime,
	ISteamUserStats_StoreStats
};

struct ISteamUserStatsImpl *SteamUserStats(void)
{
	static struct ISteamUserStatsImpl impl;

	impl.iface = &ISteamUserStats_vtbl;

	return &impl;
}
