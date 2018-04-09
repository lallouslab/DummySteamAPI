#include <inttypes.h>
#include <string.h>

#include "ISteamUser/ISteamUser018.h"
#include "CCallback.h"
#include "callbacks.h"
#include "config.h"
#include "debug.h"
#include "steam.h"

#include "ISteamUserStats.h"
#include "ISteamUserStats_priv.h"
#include "ISteamUserStats011.h"

static struct ISteamUserStatsImplCommon steam_user_stats_impl_common = {
	.is_init = STEAM_FALSE
};

MEMBER void ISteamUserStats_ctor(struct ISteamUserStats *iface)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	This->base.vtbl.ptr = NULL;
	This->common = &steam_user_stats_impl_common;

	if (!This->common->is_init)
	{
		CCallResult(&This->common->request_current_stats_call_result,
				STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_RECEIVED,
				sizeof(struct steam_callback_data_user_stats_user_stats_received));

		This->common->is_init = STEAM_TRUE;
	}
}

MEMBER static void request_current_stats_call_result(void *obj, void *param, steam_bool_t io_failure)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(obj);
	struct steam_callback_data_user_stats_user_stats_received *user_stats_received = param;

	LOG_ENTER("(This = %p, param = %p, io_failure = %u)", VOIDPTR(This), param, io_failure);

	if (io_failure || !param)
		return;

	callbacks_dispatch_callback_output(STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_RECEIVED, user_stats_received, sizeof(*user_stats_received));
}

MEMBER steam_bool_t ISteamUserStats_RequestCurrentStats(struct ISteamUserStats *iface)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	steam_bool_t retb;
	struct ISteamUser *steam_user;
	union CSteamID steam_id_user;
	steam_api_call_t api_call;

	LOG_ENTER("(This = %p)", VOIDPTR(This));

	retb = CCallResult_IsActive(&This->common->request_current_stats_call_result);
	if (retb)
		return STEAM_TRUE;

	steam_user = SteamUser018();
	if (!steam_user)
		return STEAM_FALSE;

	steam_id_user = steam_user->vtbl.v018->GetSteamID(steam_user);
	api_call = ISteamUserStats_RequestUserStats(iface, steam_id_user);

	CCallResult_Set(&This->common->request_current_stats_call_result, api_call, iface, request_current_stats_call_result);

	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamUserStats_GetStatI32(struct ISteamUserStats *iface, const char *name, int32_t *data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUserStats_GetStatFloat(struct ISteamUserStats *iface, const char *name, float *data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUserStats_SetStatI32(struct ISteamUserStats *iface, const char *name, int32_t data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %" PRIi32 ")", VOIDPTR(This), debug_str(name), data);

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUserStats_SetStatFloat(struct ISteamUserStats *iface, const char *name, float data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %f)", VOIDPTR(This), debug_str(name), data);

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUserStats_UpdateAvgRateStat(struct ISteamUserStats *iface, const char *name, float count_this_session, float session_length)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", count_this_session = %f, session_length = %f)", VOIDPTR(This), debug_str(name), count_this_session, session_length);

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUserStats_GetAchievement(struct ISteamUserStats *iface, const char *name, steam_bool_t *achieved)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(achieved));

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUserStats_SetAchievement(struct ISteamUserStats *iface, const char *name)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUserStats_ClearAchievement(struct ISteamUserStats *iface, const char *name)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUserStats_GetAchievementAndUnlockTime(struct ISteamUserStats *iface, const char *name, steam_bool_t *achieved, uint32_t *unlock_time)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", achieved = %p, unlock_time = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(achieved), VOIDPTR(unlock_time));

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUserStats_StoreStats(struct ISteamUserStats *iface)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

MEMBER int ISteamUserStats_GetAchievementIcon(struct ISteamUserStats *iface, const char *name)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));

	return 0;
}

MEMBER const char *ISteamUserStats_GetAchievementDisplayAttribute(struct ISteamUserStats *iface, const char *name, const char *key)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", key = \"%s\")", VOIDPTR(This), debug_str(name), debug_str(key));

	return "<achievement value>";
}

MEMBER steam_bool_t ISteamUserStats_IndicateAchievementProgress(struct ISteamUserStats *iface, const char *name, uint32_t cur_progress, uint32_t max_progress)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", cur_progress = %u, max_progress = %u)", VOIDPTR(This), debug_str(name), cur_progress, max_progress);

	return STEAM_FALSE;
}

MEMBER steam_api_call_t ISteamUserStats_RequestUserStats(struct ISteamUserStats *iface, union CSteamID steam_id_user)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct steam_callback_data_user_stats_user_stats_received user_stats_received;

	LOG_ENTER_NOTIMPL("(This = %p, steam_id_user = %#" PRIx64 ")", VOIDPTR(This), steam_id_user.raw);

	user_stats_received.game_id = dsa_config_get_steam_game_id();
	user_stats_received.result = STEAM_RESULT_OK;
	user_stats_received.steam_id_user = steam_id_user;

	return callbacks_dispatch_api_call_result_output(STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_RECEIVED, STEAM_FALSE, &user_stats_received, sizeof(user_stats_received));
}

MEMBER steam_api_call_t ISteamUserStats_FindOrCreateLeaderboard(struct ISteamUserStats *iface, const char *name, enum steam_user_stats_leaderboard_sort_method sort_method, enum steam_user_stats_leaderboard_display_type display_type)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct steam_callback_data_user_stats_leaderboard_find_result leaderboard_find_result;

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", sort_method = %u, display_type = %u)", VOIDPTR(This), debug_str(name), sort_method, display_type);

	leaderboard_find_result.leaderboard = 0;
	leaderboard_find_result.found = STEAM_FALSE;

	return callbacks_dispatch_api_call_result_output(STEAM_CALLBACK_TYPE_USER_STATS_LEADERBOARD_FIND_RESULT, STEAM_FALSE, &leaderboard_find_result, sizeof(leaderboard_find_result));
}

MEMBER steam_api_call_t ISteamUserStats_RequestGlobalStats(struct ISteamUserStats *iface, int history_days_count)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, history_days_count = %d)", VOIDPTR(This), history_days_count);

	return 0;
}

MEMBER steam_bool_t ISteamUserStats_GetGlobalStatI64(struct ISteamUserStats *iface, const char *name, int64_t *data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	return STEAM_FALSE;
}

MEMBER steam_bool_t ISteamUserStats_GetGlobalStatDouble(struct ISteamUserStats *iface, const char *name, double *data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	return STEAM_FALSE;
}

struct ISteamUserStats *SteamUserStats_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUserStats *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUSERSTATS_INTERFACE_VERSION_011, SteamUserStats011 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = \"%s\")", debug_str(version));

	i = 0;
	while (ifaces[i].name)
	{
		if (strcmp(ifaces[i].name, version) == 0)
		{
			if (ifaces[i].iface_getter)
				return ifaces[i].iface_getter();

			break;
		}
		i++;
	}

	WARN("Unable to find ISteamUserStats version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamUserStats_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_user_stats_impl_common.default_version)
		steam_user_stats_impl_common.default_version = version;
}

EXPORT struct ISteamUserStats *SteamUserStats(void)
{
	static struct ISteamUserStats *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_user_stats_impl_common.default_version)
	{
		steam_user_stats_impl_common.default_version = STEAMUSERSTATS_INTERFACE_VERSION_011;

		WARN("ISteamUserStats: No version specified, defaulting to \"%s\".", debug_str(steam_user_stats_impl_common.default_version));
	}

	if (!cached_iface)
		cached_iface = SteamUserStats_generic(steam_user_stats_impl_common.default_version);

	return cached_iface;
}
