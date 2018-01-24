#include <inttypes.h>
#include <string.h>

#include "callbacks.h"
#include "utils.h"

#include "ISteamUserStats.h"
#include "ISteamUserStats_priv.h"
#include "ISteamUserStats011.h"

steam_bool_t ISteamUserStats_RequestCurrentStats(struct ISteamUserStatsImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

steam_bool_t ISteamUserStats_GetStatI32(struct ISteamUserStatsImpl *This, const char *name, int32_t *data)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s, data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_GetStatFloat(struct ISteamUserStatsImpl *This, const char *name, float *data)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s, data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_SetStatI32(struct ISteamUserStatsImpl *This, const char *name, int32_t data)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s, data = %" PRIi32 ")", VOIDPTR(This), debug_str(name), data);

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_SetStatFloat(struct ISteamUserStatsImpl *This, const char *name, float data)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s, data = %f)", VOIDPTR(This), debug_str(name), data);

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_UpdateAvgRateStat(struct ISteamUserStatsImpl *This, const char *name, float count_this_session, float session_length)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s, count_this_session = %f, session_length = %f)", VOIDPTR(This), debug_str(name), count_this_session, session_length);

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_GetAchievement(struct ISteamUserStatsImpl *This, const char *name, steam_bool_t *achieved)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s, data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(achieved));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_SetAchievement(struct ISteamUserStatsImpl *This, const char *name)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s)", VOIDPTR(This), debug_str(name));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_ClearAchievement(struct ISteamUserStatsImpl *This, const char *name)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s)", VOIDPTR(This), debug_str(name));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_GetAchievementAndUnlockTime(struct ISteamUserStatsImpl *This, const char *name, steam_bool_t *achieved, uint32_t *unlock_time)
{
	LOG_ENTER_NOTIMPL("(This = %p, name = %s, achieved = %p, unlock_time = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(achieved), VOIDPTR(unlock_time));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_StoreStats(struct ISteamUserStatsImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

/* XXX BUG: steam_id_user is not a ptr */
steam_api_call_t ISteamUserStats_RequestUserStats(struct ISteamUserStatsImpl *This, union CSteamID steam_id_user)
{
	const char *game_id;

	struct
	{
		uint64_t game_id;
		enum steam_result result;
		union CSteamID steam_id_user;
	} user_stats_received;

	LOG_ENTER_NOTIMPL("(This = %p, steam_id_user = %#" PRIx64 ")", VOIDPTR(This), steam_id_user.raw);

	game_id = getenv("SteamGameId");
	if (!game_id)
	{
		WARN0("SteamGameId is not set.");
		game_id = "1";
	}

	user_stats_received.game_id = strtoull(game_id, NULL, 0);
	user_stats_received.result = STEAM_RESULT_OK;
	user_stats_received.steam_id_user = steam_id_user;

	return callbacks_dispatch_api_call_result_output(STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_RECEIVED, STEAM_FALSE, &user_stats_received, sizeof(user_stats_received));
}

struct ISteamUserStatsImpl *SteamUserStats_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUserStatsImpl *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUSERSTATS_INTERFACE_VERSION_011, SteamUserStats011 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = %s)", debug_str(version));

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

EXPORT struct ISteamUserStatsImpl *SteamUserStats(void)
{
	LOG_ENTER0("()");

	return SteamUserStats011();
}
