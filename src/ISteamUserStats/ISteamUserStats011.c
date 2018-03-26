#include "utils.h"

#include "ISteamUserStats011.h"
#include "ISteamUserStats_priv.h"

static const struct ISteamUserStats011Vtbl ISteamUserStats011_vtbl = {
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
	ISteamUserStats_StoreStats,
	INVAL_PTR,
	ISteamUserStats_GetAchievementDisplayAttribute,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamUserStats_RequestUserStats,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamUserStats *SteamUserStats011(void)
{
	static struct ISteamUserStatsImpl impl;

	impl.base.vtbl = &ISteamUserStats011_vtbl;

	return &impl.base;
}
