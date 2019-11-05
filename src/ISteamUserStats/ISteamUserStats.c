#include <inttypes.h>
#include <string.h>

#include "ISteamUser/ISteamUser019.h"
#include "CCallback.h"
#include "callbacks.h"
#include "config.h"
#include "debug.h"
#include "jobserver.h"
#include "steam.h"
#include "utils.h"
#include "vdf/vdf.h"

#include "ISteamUserStats.h"
#include "ISteamUserStats_priv.h"
#include "ISteamUserStats011.h"

static struct ISteamUserStatsImplCommon steam_user_stats_impl_common = {
	.is_init = STEAM_FALSE
};


static union CSteamID get_cur_user_id(void)
{
	struct ISteamUser *steam_user;
	union CSteamID steam_id_user;

	steam_id_user.raw = STEAM_ID_RAW_INVALID;

	steam_user = SteamUser019();
	if (!steam_user)
		return steam_id_user;

	ISteamUser019_GetSteamID(steam_user, &steam_id_user);
	return steam_id_user;
}

static struct dsa_vdf *get_user_game_stats(struct ISteamUserStatsImpl *This, union CSteamID steam_id_user)
{
	char steam_id_user_buf[32];
	union CGameID game_id;
	char game_id_buf[32];

	snprintf(steam_id_user_buf, sizeof(steam_id_user_buf), "%" PRIu64, steam_id_user.raw);

	game_id = dsa_config_get_steam_game_id();
	snprintf(game_id_buf, sizeof(game_id_buf), "%" PRIu64, game_id.raw);

	return dsa_vdf_mutate_as_list(dsa_vdf_open_path(This->common->stats, "Users", steam_id_user_buf, "Games", game_id_buf, NULL));
}

static struct dsa_vdf *get_user_game_achievements(struct ISteamUserStatsImpl *This, union CSteamID steam_id_user)
{
	return dsa_vdf_mutate_as_list(dsa_vdf_open_path(get_user_game_stats(This, steam_id_user), "Achievements", NULL));
}

static struct dsa_vdf *get_user_game_achievement(struct ISteamUserStatsImpl *This, union CSteamID steam_id_user, const char *name)
{
	return dsa_vdf_mutate_as_list(dsa_vdf_open_path(get_user_game_achievements(This, steam_id_user), name, NULL));
}

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
		This->common->stats_filename = dsa_utils_concat(dsa_config_get_data_dir(), "/ISteamUserStats.vdf", NULL);
		This->common->stats = NULL;

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

	steam_user = SteamUser019();
	if (!steam_user)
		return STEAM_FALSE;

	ISteamUser019_GetSteamID(steam_user, &steam_id_user);
	api_call = ISteamUserStats_RequestUserStats(iface, steam_id_user);

	CCallResult_Set(&This->common->request_current_stats_call_result, api_call, iface, request_current_stats_call_result);

	return STEAM_TRUE;
}

EXPORT steam_bool_t SteamAPI_ISteamUserStats_RequestCurrentStats(struct ISteamUserStats *iface)
{
	return ISteamUserStats_RequestCurrentStats(iface);
}

MEMBER steam_bool_t ISteamUserStats_GetStatI32(struct ISteamUserStats *iface, const char *name, int32_t *data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct dsa_vdf *vdf;
	int d;

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	if (!This->common->stats)
		return STEAM_FALSE;

	vdf = get_user_game_achievement(This, get_cur_user_id(), name);
	if (!vdf)
		return STEAM_FALSE;

	dsa_vdf_get_int(dsa_vdf_mutate_as_int(dsa_vdf_open_path(vdf, "CurProgress", NULL)), &d);
	*data = d;

	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamUserStats_GetStatFloat(struct ISteamUserStats *iface, const char *name, float *data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct dsa_vdf *vdf;
	float f;

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	if (!This->common->stats)
		return STEAM_FALSE;

	vdf = get_user_game_achievement(This, get_cur_user_id(), name);
	if (!vdf)
		return STEAM_FALSE;

	dsa_vdf_get_float(dsa_vdf_mutate_as_float(dsa_vdf_open_path(vdf, "CurProgress", NULL)), &f);
	*data = f;

	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamUserStats_SetStatI32(struct ISteamUserStats *iface, const char *name, int32_t data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct dsa_vdf *vdf;

	LOG_ENTER("(This = %p, name = \"%s\", data = %" PRIi32 ")", VOIDPTR(This), debug_str(name), data);

	if (!This->common->stats)
		return STEAM_FALSE;

	vdf = get_user_game_achievement(This, get_cur_user_id(), name);
	if (!vdf)
		return STEAM_FALSE;

	dsa_vdf_set_int(dsa_vdf_mutate_as_int(dsa_vdf_open_path(vdf, "CurProgress", NULL)), data);

	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamUserStats_SetStatFloat(struct ISteamUserStats *iface, const char *name, float data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct dsa_vdf *vdf;

	LOG_ENTER("(This = %p, name = \"%s\", data = %f)", VOIDPTR(This), debug_str(name), data);

	if (!This->common->stats)
		return STEAM_FALSE;

	vdf = get_user_game_achievement(This, get_cur_user_id(), name);
	if (!vdf)
		return STEAM_FALSE;

	dsa_vdf_set_float(dsa_vdf_mutate_as_float(dsa_vdf_open_path(vdf, "CurProgress", NULL)), data);

	return STEAM_TRUE;
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
	struct dsa_vdf *vdf;
	int val = 0;

	LOG_ENTER("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(achieved));

	if (!This->common->stats)
		return STEAM_FALSE;

	vdf = get_user_game_achievement(This, get_cur_user_id(), name);
	if (!vdf)
		return STEAM_FALSE;

	dsa_vdf_get_int(dsa_vdf_mutate_as_int(dsa_vdf_open_path(vdf, "Achieved", NULL)), &val);
	*achieved = !!val;
	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamUserStats_SetAchievement(struct ISteamUserStats *iface, const char *name)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct dsa_vdf *vdf;

	LOG_ENTER("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));

	if (!This->common->stats)
		return STEAM_FALSE;

	vdf = get_user_game_achievement(This, get_cur_user_id(), name);
	if (!vdf)
		return STEAM_FALSE;

	dsa_vdf_set_int(dsa_vdf_mutate_as_int(dsa_vdf_open_path(vdf, "Achieved", NULL)), 1);
	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamUserStats_ClearAchievement(struct ISteamUserStats *iface, const char *name)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct dsa_vdf *vdf;

	LOG_ENTER("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));

	if (!This->common->stats)
		return STEAM_FALSE;

	vdf = get_user_game_achievement(This, get_cur_user_id(), name);
	if (!vdf)
		return STEAM_FALSE;

	dsa_vdf_set_int(dsa_vdf_mutate_as_int(dsa_vdf_open_path(vdf, "Achieved", NULL)), 0);
	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamUserStats_GetAchievementAndUnlockTime(struct ISteamUserStats *iface, const char *name, steam_bool_t *achieved, uint32_t *unlock_time)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", achieved = %p, unlock_time = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(achieved), VOIDPTR(unlock_time));

	return STEAM_FALSE;
}

struct store_stats_worker_arg
{
	struct ISteamUserStatsImpl *This;
};

static void store_stats_worker(void *arg)
{
	struct store_stats_worker_arg *jarg = (struct store_stats_worker_arg *)arg;
	struct steam_callback_data_user_stats_user_stats_stored user_stats_stored;
	char *data;
	size_t data_size;
	struct dsa_vdf *achievements;
	size_t achievement_count;

	user_stats_stored.game_id = dsa_config_get_steam_game_id();
	user_stats_stored.result = STEAM_RESULT_OK;

	data = dsa_vdf_serialize(jarg->This->common->stats, &data_size);
	dsa_utils_file_write(jarg->This->common->stats_filename, data, data_size);
	free(data);

	callbacks_dispatch_callback_output(STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_STORED, &user_stats_stored, sizeof(user_stats_stored));

	achievements = get_user_game_achievements(jarg->This, get_cur_user_id());
	dsa_vdf_list_get_entry_count(achievements, &achievement_count);
	for (size_t i = 0; i < achievement_count; i++)
	{
		struct dsa_vdf *vdf = dsa_vdf_mutate_as_list(dsa_vdf_list_get_entry_by_idx(achievements, i));
		const char *achievement_name;
		struct steam_callback_data_user_stats_user_achievement_stored user_achievement_stored;
		int val;
		steam_bool_t achieved;

		if (!vdf)
			continue;

		dsa_vdf_get_int(dsa_vdf_mutate_as_int(dsa_vdf_open_path(vdf, "Achieved", NULL)), &val);
		achieved = !!val;

		if (!achieved)
			continue;

		dsa_vdf_get_name(vdf, &achievement_name);

		user_achievement_stored.game_id = dsa_config_get_steam_game_id();
		user_achievement_stored.is_group_achievement = STEAM_FALSE;
		strncpy(user_achievement_stored.achievement_name, achievement_name, sizeof(user_achievement_stored.achievement_name));
		user_achievement_stored.achievement_name[sizeof(user_achievement_stored.achievement_name) - 1] = '\0';
		user_achievement_stored.cur_progress = 0;
		user_achievement_stored.max_progress = 0;

		callbacks_dispatch_callback_output(STEAM_CALLBACK_TYPE_USER_STATS_USER_ACHIEVEMENT_STORED, &user_achievement_stored, sizeof(user_achievement_stored));
	}
}

MEMBER steam_bool_t ISteamUserStats_StoreStats(struct ISteamUserStats *iface)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct store_stats_worker_arg arg;

	LOG_ENTER("(This = %p)", VOIDPTR(This));

	if (!This->common->stats)
		return STEAM_FALSE;

	arg.This = This;

	dsa_jobserver_schedule(store_stats_worker, &arg, sizeof(arg));
	return STEAM_TRUE;
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

struct indicate_achievement_worker_arg
{
	struct ISteamUserStatsImpl *This;
	struct dsa_vdf *vdf;
};

static void indicate_achievement_worker(void *arg)
{
	struct indicate_achievement_worker_arg *jarg = (struct indicate_achievement_worker_arg *)arg;
	struct steam_callback_data_user_stats_user_stats_stored user_stats_stored;
	struct steam_callback_data_user_stats_user_achievement_stored user_achievement_stored;
	const char *achievement_name;

	user_stats_stored.game_id = dsa_config_get_steam_game_id();
	user_stats_stored.result = STEAM_RESULT_OK;

	callbacks_dispatch_callback_output(STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_STORED, &user_stats_stored, sizeof(user_stats_stored));

	dsa_vdf_get_name(jarg->vdf, &achievement_name);

	user_achievement_stored.game_id = user_stats_stored.game_id;
	user_achievement_stored.is_group_achievement = STEAM_FALSE;
	strncpy(user_achievement_stored.achievement_name, achievement_name, sizeof(user_achievement_stored.achievement_name));
	user_achievement_stored.achievement_name[sizeof(user_achievement_stored.achievement_name) - 1] = '\0';
	user_achievement_stored.cur_progress = 0;
	user_achievement_stored.max_progress = 0;

	callbacks_dispatch_callback_output(STEAM_CALLBACK_TYPE_USER_STATS_USER_ACHIEVEMENT_STORED, &user_achievement_stored, sizeof(user_achievement_stored));
}

MEMBER steam_bool_t ISteamUserStats_IndicateAchievementProgress(struct ISteamUserStats *iface, const char *name, uint32_t cur_progress, uint32_t max_progress)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct dsa_vdf *vdf;
	int val;
	steam_bool_t achieved;
	struct indicate_achievement_worker_arg arg;

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", cur_progress = %u, max_progress = %u)", VOIDPTR(This), debug_str(name), cur_progress, max_progress);

	if (!This->common->stats)
		return STEAM_FALSE;

	vdf = get_user_game_achievement(This, get_cur_user_id(), name);
	if (!vdf)
		return STEAM_FALSE;

	dsa_vdf_get_int(dsa_vdf_mutate_as_int(dsa_vdf_open_path(vdf, "Achieved", NULL)), &val);
	achieved = !!val;

	if (achieved)
		return STEAM_FALSE;

	if (cur_progress > max_progress)
		return STEAM_FALSE;

	arg.This = This;
	arg.vdf = vdf;

	dsa_jobserver_schedule(indicate_achievement_worker, &arg, sizeof(arg));
	return STEAM_TRUE;
}

struct request_user_stats_worker_arg
{
	struct ISteamUserStatsImpl *This;
	union CSteamID steam_id_user;
	steam_api_call_t api_call;
};

static void request_user_stats_worker(void *arg)
{
	struct request_user_stats_worker_arg *jarg = (struct request_user_stats_worker_arg *)arg;
	struct steam_callback_data_user_stats_user_stats_received user_stats_received;
	steam_bool_t io_failure = STEAM_FALSE;

	user_stats_received.game_id = dsa_config_get_steam_game_id();
	user_stats_received.result = STEAM_RESULT_OK;
	user_stats_received.steam_id_user = jarg->steam_id_user;

	if (!jarg->This->common->stats)
	{
		size_t file_size;
		char *data;
		struct dsa_vdf *vdf;

		data = dsa_utils_file_get_contents(jarg->This->common->stats_filename, &file_size);

		vdf = dsa_vdf_parse(data, file_size);
		free(data);

		if (!vdf)
			vdf = dsa_vdf_set_list(dsa_vdf_create_root("ISteamUserStats"));

		if (!vdf)
		{
			user_stats_received.result = STEAM_RESULT_FAIL;
			io_failure = STEAM_TRUE;
		}

		jarg->This->common->stats = vdf;
	}

	callbacks_dispatch_api_call_result_output(jarg->api_call, STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_RECEIVED, io_failure, &user_stats_received, sizeof(user_stats_received));
}

MEMBER steam_api_call_t ISteamUserStats_RequestUserStats(struct ISteamUserStats *iface, union CSteamID steam_id_user)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct request_user_stats_worker_arg arg;

	LOG_ENTER("(This = %p, steam_id_user = %#" PRIx64 ")", VOIDPTR(This), steam_id_user.raw);

	arg.This = This;
	arg.steam_id_user = steam_id_user;
	arg.api_call = callbacks_await_api_call_result_output();

	dsa_jobserver_schedule(request_user_stats_worker, &arg, sizeof(arg));
	return arg.api_call;
}

MEMBER steam_api_call_t ISteamUserStats_FindOrCreateLeaderboard(struct ISteamUserStats *iface, const char *name, enum steam_user_stats_leaderboard_sort_method sort_method, enum steam_user_stats_leaderboard_display_type display_type)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct steam_callback_data_user_stats_leaderboard_find_result leaderboard_find_result;
	steam_api_call_t api_call;

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", sort_method = %u, display_type = %u)", VOIDPTR(This), debug_str(name), sort_method, display_type);

	leaderboard_find_result.leaderboard = 0;
	leaderboard_find_result.found = STEAM_FALSE;

	api_call = callbacks_await_api_call_result_output();
	callbacks_dispatch_api_call_result_output(api_call, STEAM_CALLBACK_TYPE_USER_STATS_LEADERBOARD_FIND_RESULT, STEAM_FALSE, &leaderboard_find_result, sizeof(leaderboard_find_result));
	return api_call;
}

EXPORT steam_api_call_t SteamAPI_ISteamUserStats_FindOrCreateLeaderboard(struct ISteamUserStats *iface, const char *name, enum steam_user_stats_leaderboard_sort_method sort_method, enum steam_user_stats_leaderboard_display_type display_type)
{
	return ISteamUserStats_FindOrCreateLeaderboard(iface, name, sort_method, display_type);
}

MEMBER steam_api_call_t ISteamUserStats_FindLeaderboard(struct ISteamUserStats *iface, const char *name)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct steam_callback_data_user_stats_leaderboard_find_result leaderboard_find_result;
	steam_api_call_t api_call;

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));

	leaderboard_find_result.leaderboard = 0;
	leaderboard_find_result.found = STEAM_FALSE;

	api_call = callbacks_await_api_call_result_output();
	callbacks_dispatch_api_call_result_output(api_call, STEAM_CALLBACK_TYPE_USER_STATS_LEADERBOARD_FIND_RESULT, STEAM_FALSE, &leaderboard_find_result, sizeof(leaderboard_find_result));
	return api_call;
}

MEMBER steam_api_call_t ISteamUserStats_GetNumberOfCurrentPlayers(struct ISteamUserStats *iface)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct steam_callback_data_user_stats_number_of_current_players number_of_current_players;
	steam_api_call_t api_call;

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	number_of_current_players.success = 0;
	number_of_current_players.player_count = 0;

	api_call = callbacks_await_api_call_result_output();
	callbacks_dispatch_api_call_result_output(api_call, STEAM_CALLBACK_TYPE_USER_STATS_NUMBER_OF_CURRENT_PLAYERS, STEAM_FALSE, &number_of_current_players, sizeof(number_of_current_players));
	return api_call;
}

MEMBER steam_api_call_t ISteamUserStats_RequestGlobalStats(struct ISteamUserStats *iface, int history_days_count)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);
	struct steam_callback_data_user_stats_global_stats_received global_stats_received;
	steam_api_call_t api_call;

	LOG_ENTER_NOTIMPL("(This = %p, history_days_count = %d)", VOIDPTR(This), history_days_count);

	global_stats_received.game_id = dsa_config_get_steam_game_id();
	global_stats_received.result = STEAM_RESULT_OK;

	api_call = callbacks_await_api_call_result_output();
	callbacks_dispatch_api_call_result_output(api_call, STEAM_CALLBACK_TYPE_USER_STATS_GLOBAL_STATS_RECEIVED, STEAM_FALSE, &global_stats_received, sizeof(global_stats_received));
	return api_call;
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
