#include <inttypes.h>
#include <string.h>

#include "callbacks.h"
#include "debug.h"
#include "utils.h"

#include "ISteamUserStats.h"
#include "ISteamUserStats_priv.h"
#include "ISteamUserStats011.h"

static const char *steam_user_stats_version = NULL;

steam_bool_t ISteamUserStats_RequestCurrentStats(struct ISteamUserStats *iface)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

steam_bool_t ISteamUserStats_GetStatI32(struct ISteamUserStats *iface, const char *name, int32_t *data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_GetStatFloat(struct ISteamUserStats *iface, const char *name, float *data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(data));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_SetStatI32(struct ISteamUserStats *iface, const char *name, int32_t data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %" PRIi32 ")", VOIDPTR(This), debug_str(name), data);

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_SetStatFloat(struct ISteamUserStats *iface, const char *name, float data)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %f)", VOIDPTR(This), debug_str(name), data);

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_UpdateAvgRateStat(struct ISteamUserStats *iface, const char *name, float count_this_session, float session_length)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", count_this_session = %f, session_length = %f)", VOIDPTR(This), debug_str(name), count_this_session, session_length);

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_GetAchievement(struct ISteamUserStats *iface, const char *name, steam_bool_t *achieved)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", data = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(achieved));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_SetAchievement(struct ISteamUserStats *iface, const char *name)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_ClearAchievement(struct ISteamUserStats *iface, const char *name)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_GetAchievementAndUnlockTime(struct ISteamUserStats *iface, const char *name, steam_bool_t *achieved, uint32_t *unlock_time)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\", achieved = %p, unlock_time = %p)", VOIDPTR(This), debug_str(name), VOIDPTR(achieved), VOIDPTR(unlock_time));

	return STEAM_FALSE;
}

steam_bool_t ISteamUserStats_StoreStats(struct ISteamUserStats *iface)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

/* XXX BUG: steam_id_user is not a ptr */
steam_api_call_t ISteamUserStats_RequestUserStats(struct ISteamUserStats *iface, union CSteamID steam_id_user)
{
	struct ISteamUserStatsImpl *This = impl_from_ISteamUserStats(iface);

	const char *game_id;

	PACKED_STRUCT
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

	if (!steam_user_stats_version)
		steam_user_stats_version = version;
}

EXPORT struct ISteamUserStats *SteamUserStats(void)
{
	static struct ISteamUserStats *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_user_stats_version)
	{
		steam_user_stats_version = STEAMUSERSTATS_INTERFACE_VERSION_011;

		WARN("ISteamUserStats: No version specified, defaulting to \"%s\".", debug_str(steam_user_stats_version));
	}

	if (!cached_iface)
		cached_iface = SteamUserStats_generic(steam_user_stats_version);

	return cached_iface;
}
