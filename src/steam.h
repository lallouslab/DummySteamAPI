#ifndef STEAM_H
#define STEAM_H

#include <stdint.h>
#include <inttypes.h>

#include "macros.h"

enum steam_bool
{
	STEAM_FALSE = 0u,
	STEAM_TRUE  = 1u
};

typedef enum steam_bool steam_bool_t;

typedef uint32_t steam_account_id_t;
typedef uint64_t steam_api_call_t;
typedef uint32_t steam_app_id_t;
typedef uint32_t steam_auth_ticket_handle_t;
typedef int32_t  steam_handle_pipe_t;
typedef uint32_t steam_mod_id_t;
typedef int32_t  steam_user_t;

enum steam_account_instance
{
	STEAM_ACCOUNT_INSTANCE_USER_DESKTOP = 1u << 0,
	STEAM_ACCOUNT_INSTANCE_USER_CONSOLE = 1u << 1,
	STEAM_ACCOUNT_INSTANCE_USER_WEB     = 1u << 2,
};

enum steam_account_type
{
	STEAM_ACCOUNT_TYPE_INVALID = 0u,
	STEAM_ACCOUNT_TYPE_INDIVIDUAL = 1u,
	STEAM_ACCOUNT_TYPE_MULTISEAT = 2u,
	STEAM_ACCOUNT_TYPE_GAMESERVER = 3u,
	STEAM_ACCOUNT_TYPE_ANONGAMESERVER = 4u,
	STEAM_ACCOUNT_TYPE_PENDING = 5u,
	STEAM_ACCOUNT_TYPE_CONTENTSERVER = 6u,
	STEAM_ACCOUNT_TYPE_CLAN = 7u,
	STEAM_ACCOUNT_TYPE_CHAT = 8u,
	STEAM_ACCOUNT_TYPE_CONSOLEUSER = 9u,
	STEAM_ACCOUNT_TYPE_ANONUSER = 10u,
	STEAM_ACCOUNT_TYPE_MAX
};

enum steam_game_id_type
{
	STEAM_GAME_ID_TYPE_APP = 0u,
	STEAM_GAME_ID_TYPE_GAME_MOD = 1u,
	STEAM_GAME_ID_TYPE_SHORTCUT = 2u,
	STEAM_GAME_ID_TYPE_P2P = 3u
};

enum steam_game_server_mode
{
	STEAM_GAME_SERVER_MODE_INVALID = 0,
	STEAM_GAME_SERVER_MODE_NO_AUTH = 1,
	STEAM_GAME_SERVER_MODE_AUTH = 2,
	STEAM_GAME_SERVER_MODE_SECAUTH = 3
};

enum steam_notification_position
{
	STEAM_NOTIFICATION_POSITION_TOP_LEFT = 0u,
	STEAM_NOTIFICATION_POSITION_TOP_RIGHT = 1u,
	STEAM_NOTIFICATION_POSITION_BOTTOM_LEFT = 2u,
	STEAM_NOTIFICATION_POSITION_BOTTOM_RIGHT = 3u
};

enum steam_result
{
	STEAM_RESULT_OK = 1u,
	STEAM_RESULT_FAIL = 2u
	/* ... */
};

enum steam_universe
{
	STEAM_UNIVERSE_INVALID = 0u,
	STEAM_UNIVERSE_PUBLIC = 1u,
	STEAM_UNIVERSE_BETA = 2u,
	STEAM_UNIVERSE_INTERNAL = 3u,
	STEAM_UNIVERSE_DEV = 4u,
	STEAM_UNIVERSE_MAX
};

union CGameID
{
	struct
	{
		steam_app_id_t app_id : 24;
		enum steam_game_id_type type : 8;
		steam_mod_id_t mod_id : 32;
	} bits;
	uint64_t raw;
};

union CSteamID
{
	struct
	{
		steam_account_id_t account_id : 32;
		enum steam_account_instance account_instance : 20;
		enum steam_account_type account_type : 4;
		enum steam_universe universe : 8;
	} bits;
	uint64_t raw;
};

#endif /* STEAM_H */
