#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "debug.h"

#define CASE_STR(x) case (x): return #x

static FILE *log_file = NULL;

enum dsa_log_level dsa_debug_get_log_level(void)
{
	return dsa_config_get_log_level();
}

FILE *dsa_debug_get_log_file(void)
{
	if (!log_file)
		log_file = stderr;//fopen("log.log", "w");

	return log_file;
}

const char *dsa_debug_steam_callback_type(enum steam_callback_type type)
{
	switch (type)
	{
		CASE_STR(STEAM_CALLBACK_TYPE_USER);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STEAM_SERVERS_CONNECTED);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STEAM_SERVERS_CONNECT_FAILURE);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STEAM_SERVERS_DISCONNECTED);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_BEGIN_LOGON_RETRY);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_CLIENT_GAME_SERVER_DENY);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_PRIMARY_CHAT_DESTINATION_SET_OLD);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_GS_POLICY_RESPONSE);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_IPC_FAILURE);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_LICENSES_UPDATED);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_APP_LIFETIME_NOTICE);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_DRM_SDK_FILE_TRANSFER_RESULT);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_VALIDATE_AUTH_TICKET_RESPONSE);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_MICRO_TXN_AUTHORIZATION_RESPONSE);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_ENCRYPTED_APP_TICKET_RESPONSE);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_GET_AUTH_SESSION_TICKET_RESPONSE);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_GAME_WEB_CALLBACK);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STORE_AUTH_URL_RESPONSE);

		CASE_STR(STEAM_CALLBACK_TYPE_GAME_SERVER);
		CASE_STR(STEAM_CALLBACK_TYPE_GAME_SERVER_CLIENT_APPROVE);
		CASE_STR(STEAM_CALLBACK_TYPE_GAME_SERVER_CLIENT_DENY);

		CASE_STR(STEAM_CALLBACK_TYPE_FRIENDS);
		CASE_STR(STEAM_CALLBACK_TYPE_FRIENDS_PERSONA_STATE_CHANGE);
		CASE_STR(STEAM_CALLBACK_TYPE_FRIENDS_GAME_OVERLAY_ACTIVATED);
		CASE_STR(STEAM_CALLBACK_TYPE_FRIENDS_GAME_SERVER_CHANGE_REQUESTED);
		CASE_STR(STEAM_CALLBACK_TYPE_FRIENDS_GAME_LOBBY_JOIN_REQUESTED);
		CASE_STR(STEAM_CALLBACK_TYPE_FRIENDS_AVATAR_IMAGE_LOADED);
		CASE_STR(STEAM_CALLBACK_TYPE_FRIENDS_CLAN_OFFICER_LIST_RESPONSE);
		CASE_STR(STEAM_CALLBACK_TYPE_FRIENDS_FRIEND_RICH_PRESENCE_UPDATE);
		CASE_STR(STEAM_CALLBACK_TYPE_FRIENDS_GAME_RICH_PRESENCE_JOIN_REQUESTED);

		CASE_STR(STEAM_CALLBACK_TYPE_BILLING);

		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_FAVORITES_LIST_CHANGED_OLD);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_FAVORITES_LIST_CHANGED);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_INVITE);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_ENTER);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_DATA_UPDATE);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_CHAT_UPDATE);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_CHAT_MSG);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_ADMIN_CHANGE);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_GAME_CREATED);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_MATCH_LIST);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_CLOSING);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_KICKED);
		CASE_STR(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_CREATED);

		CASE_STR(STEAM_CALLBACK_TYPE_CONTENT_SERVER);

		CASE_STR(STEAM_CALLBACK_TYPE_UTILS);
		CASE_STR(STEAM_CALLBACK_TYPE_UTILS_IP_COUNTRY);
		CASE_STR(STEAM_CALLBACK_TYPE_UTILS_LOW_BATTERY_POWER);
		CASE_STR(STEAM_CALLBACK_TYPE_UTILS_STEAM_API_CALL_COMPLETED);
		CASE_STR(STEAM_CALLBACK_TYPE_UTILS_STEAM_SHUTDOWN);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_FRIENDS);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_USER);

		CASE_STR(STEAM_CALLBACK_TYPE_APPS);

		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_RECEIVED);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_STORED);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_USER_ACHIEVEMENT_STORED);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_LEADERBOARD_FIND_RESULT);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_LEADERBOARD_SCORES_DOWNLOADED);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_LEADERBOARD_SCORE_UPLOADED);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_NUMBER_OF_CURRENT_PLAYERS);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_UNLOADED);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_USER_ACHIEVEMENT_ICON_FETCHED);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_GLOBAL_ACHIEVEMENT_PERCENTAGES_READY);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_LEADERBOARD_UGC_SET);
		CASE_STR(STEAM_CALLBACK_TYPE_USER_STATS_GLOBAL_STATS_RECEIVED);

		CASE_STR(STEAM_CALLBACK_TYPE_NETWORKING);
		CASE_STR(STEAM_CALLBACK_TYPE_NETWORKING_SOCKET_STATUS_CALLBACK);
		CASE_STR(STEAM_CALLBACK_TYPE_NETWORKING_P2P_SESSION_REQUEST);
		CASE_STR(STEAM_CALLBACK_TYPE_NETWORKING_P2P_SESSION_CONNECT_FAIL);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_REMOTE_STORAGE);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_DEPOT_BUILDER);

		CASE_STR(STEAM_CALLBACK_TYPE_GAME_SERVER_ITEMS);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_UTILS);

		CASE_STR(STEAM_CALLBACK_TYPE_GAME_COORDINATOR);

		CASE_STR(STEAM_CALLBACK_TYPE_GAME_SERVER_STATS);

		CASE_STR(STEAM_CALLBACK_TYPE_2ASYNC);

		CASE_STR(STEAM_CALLBACK_TYPE_GAME_STATS);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_HTTP);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_SCREENSHOTS);

		CASE_STR(STEAM_CALLBACK_TYPE_SCREENSHOTS);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_AUDIO);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_UNIFIED_MESSAGES);

		CASE_STR(STEAM_CALLBACK_TYPE_STREAM_LAUNCHER);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_CONTROLLER);

		CASE_STR(STEAM_CALLBACK_TYPE_CONTROLLER);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_PARENTAL_SETTINGS);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_DEVICE_AUTH);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_NETWORK_DEVICE_MANAGER);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_MUSIC);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_REMOTE_CLIENT_MANAGER);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_UGC);
		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_UGC_QUERY_COMPLETED);
		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_UGC_REQUEST_UGC_DETAILS_RESULT);
		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_UGC_CREATE_ITEM_RESULT);
		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_UGC_SUBMIT_ITEM_UPDATE_RESULT);
		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_UGC_ITEM_INSTALLED);

		CASE_STR(STEAM_CALLBACK_TYPE_STREAM_CLIENT);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_PRODUCT_BUILDER);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_SHORTCUTS);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_REMOTE_CONTROL_MANAGER);

		CASE_STR(STEAM_CALLBACK_TYPE_APP_LIST);

		CASE_STR(STEAM_CALLBACK_TYPE_MUSIC);

		CASE_STR(STEAM_CALLBACK_TYPE_MUSIC_REMOTE);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_VR);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_GAME_NOTIFICATION);

		CASE_STR(STEAM_CALLBACK_TYPE_GAME_NOTIFICATION);

		CASE_STR(STEAM_CALLBACK_TYPE_HTML_SURFACE);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_VIDEO);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_INVENTORY);

		CASE_STR(STEAM_CALLBACK_TYPE_CLIENT_BLUETOOTH_MANAGER);

		case STEAM_CALLBACK_TYPE_MAX:
		default:
			break;
	}

	return "<unknown>";
}
