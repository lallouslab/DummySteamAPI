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
typedef int32_t  steam_handle_pipe_t;
typedef uint32_t steam_mod_id_t;
typedef int32_t  steam_user_t;

enum steam_account_instance
{
	STEAM_ACCOUNT_INSTANCE_INVALID = 0u,
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

enum steam_id_raw
{
	STEAM_ID_RAW_INVALID = 0u
};

enum steam_lobby_type
{
	STEAM_LOBBY_TYPE_PRIVATE = 0u,
	STEAM_LOBBY_TYPE_FRIENDS_ONLY = 1u,
	STEAM_LOBBY_TYPE_PUBLIC = 2u,
	STEAM_LOBBY_TYPE_INVISIBLE = 3u
};

enum steam_result
{
	STEAM_RESULT_OK = 1u,
	STEAM_RESULT_FAIL = 2u,
	STEAM_RESULT_NO_CONNECTION = 3u,
	STEAM_RESULT_NO_CONNECTION_RETRY = 4u,
	STEAM_RESULT_INVALID_PASSWORD = 5u,
	STEAM_RESULT_LOGGED_IN_ELSEWHERE = 6u,
	STEAM_RESULT_INVALID_PROTOCOL_VER = 7u,
	STEAM_RESULT_INVALID_PARAM = 8u,
	STEAM_RESULT_FILE_NOT_FOUND = 9u,
	STEAM_RESULT_BUSY = 10u,
	STEAM_RESULT_INVALID_STATE = 11u,
	STEAM_RESULT_INVALID_NAME = 12u,
	STEAM_RESULT_INVALID_EMAIL = 13u,
	STEAM_RESULT_DUPLICATE_NAME = 14u,
	STEAM_RESULT_ACCESS_DENIED = 15u,
	STEAM_RESULT_TIMEOUT = 16u,
	STEAM_RESULT_BANNED = 17u,
	STEAM_RESULT_ACCOUNT_NOT_FOUND = 18u,
	STEAM_RESULT_INVALID_STEAM_ID = 19u,
	STEAM_RESULT_SERVICE_UNAVAILABLE = 20u,
	STEAM_RESULT_NOT_LOGGED_ON = 21u,
	STEAM_RESULT_PENDING = 22u,
	STEAM_RESULT_ENCRYPTION_FAILURE = 23u,
	STEAM_RESULT_INSUFFICIENT_PRIVILEGE = 24u,
	STEAM_RESULT_LIMIT_EXCEEDED = 25u,
	STEAM_RESULT_REVOKED = 26u,
	STEAM_RESULT_EXPIRED = 27u,
	STEAM_RESULT_ALREADY_REDEEMED = 28u,
	STEAM_RESULT_DUPLICATE_REQUEST = 29u,
	STEAM_RESULT_ALREADY_OWNED = 30u,
	STEAM_RESULT_IP_NOT_FOUND = 31u,
	STEAM_RESULT_PERSIST_FAILED = 32u,
	STEAM_RESULT_LOCKING_FAILED = 33u,
	STEAM_RESULT_LOGON_SESSION_REPLACED = 34u,
	STEAM_RESULT_CONNECT_FAILED = 35u,
	STEAM_RESULT_HANDSHAKE_FAILED = 36u,
	STEAM_RESULT_IO_FAILURE = 37u,
	STEAM_RESULT_REMOTE_DISCONNECT = 38u,
	STEAM_RESULT_SHOPPING_CART_NOT_FOUND = 39u,
	STEAM_RESULT_BLOCKED = 40u,
	STEAM_RESULT_IGNORED = 41u,
	STEAM_RESULT_NO_MATCH = 42u,
	STEAM_RESULT_ACCOUNT_DISABLED = 43u,
	STEAM_RESULT_SERVICE_READ_ONLY = 44u,
	STEAM_RESULT_ACCOUNT_NOT_FEATURED = 45u,
	STEAM_RESULT_ADMINISTRATOR_OK = 46u,
	STEAM_RESULT_CONTENT_VERSION = 47u,
	STEAM_RESULT_TRY_ANOTHER_CM = 48u,
	STEAM_RESULT_PASSWORD_REQUIRED_TO_KICK_SESSION = 49u,
	STEAM_RESULT_ALREADY_LOGGED_IN_ELSEWHERE = 50u,
	STEAM_RESULT_SUSPENDED = 51u,
	STEAM_RESULT_CANCELLED = 52u,
	STEAM_RESULT_DATA_CORRUPTION = 53u,
	STEAM_RESULT_DISK_FULL = 54u,
	STEAM_RESULT_REMOTE_CALL_FAILED = 55u,
	STEAM_RESULT_PASSWORD_UNSET = 56u,
	STEAM_RESULT_EXTERNAL_ACCOUNT_UNLINKED = 57u,
	STEAM_RESULT_PSN_TICKET_INVALID = 58u,
	STEAM_RESULT_EXTERNAL_ACCOUNT_ALREADY_LINKED = 59u,
	STEAM_RESULT_REMOTE_FILE_CONFLICT = 60u,
	STEAM_RESULT_ILLEGAL_PASSWORD = 61u,
	STEAM_RESULT_SAME_AS_PREVIOUS_VALUE = 62u,
	STEAM_RESULT_ACCOUNT_LOGON_DENIED = 63u,
	STEAM_RESULT_CANNOT_USE_OLD_PASSWORD = 64u,
	STEAM_RESULT_INVALID_LOGIN_AUTH_CODE = 65u,
	STEAM_RESULT_ACCOUNT_LOGON_DENIED_NO_MAIL = 66u,
	STEAM_RESULT_HARDWARE_NOT_CAPABLE_OF_IPT = 67u,
	STEAM_RESULT_IPT_INIT_ERROR = 68u,
	STEAM_RESULT_PARENTAL_CONTROL_RESTRICTED = 69u,
	STEAM_RESULT_FACEBOOK_QUERY_ERROR = 70u,
	STEAM_RESULT_EXPIRED_LOGIN_AUTH_CODE = 71u,
	STEAM_RESULT_IP_LOGIN_RESTRICTION_FAILED = 72u,
	STEAM_RESULT_ACCOUNT_LOCKED_DOWN = 73u,
	STEAM_RESULT_ACCOUNT_LOGON_DENIED_VERIFIED_EMAIL_REQUIRED = 74u,
	STEAM_RESULT_NO_MATCHING_URL = 75u,
	STEAM_RESULT_BAD_RESPONSE = 76u,
	STEAM_RESULT_REQUIRE_PASSWORD_RE_ENTRY = 77u,
	STEAM_RESULT_VALUE_OUT_OF_RANGE = 78u,
	STEAM_RESULT_UNEXPECTED_ERROR = 79u,
	STEAM_RESULT_DISABLED = 80u,
	STEAM_RESULT_INVALID_CEG_SUBMISSION = 81u,
	STEAM_RESULT_RESTRICTED_DEVICE = 82u,
	STEAM_RESULT_REGION_LOCKED = 83u,
	STEAM_RESULT_RATE_LIMIT_EXCEEDED = 84u,
	STEAM_RESULT_ACCOUNT_LOGIN_DENIED_NEED_TWO_FACTOR = 85u,
	STEAM_RESULT_ITEM_DELETED = 86u,
	STEAM_RESULT_ACCOUNT_LOGIN_DENIED_THROTTLE = 87u,
	STEAM_RESULT_TWO_FACTOR_CODE_MISMATCH = 88u,
	STEAM_RESULT_TWO_FACTOR_ACTIVATION_CODE_MISMATCH = 89u,
	STEAM_RESULT_ACCOUNT_ASSOCIATED_TO_MULTIPLE_PARTNERS = 90u,
	STEAM_RESULT_NOT_MODIFIED = 91u,
	STEAM_RESULT_NO_MOBILE_DEVICE = 92u,
	STEAM_RESULT_TIME_NOT_SYNCED = 93u,
	STEAM_RESULT_SMS_CODE_FAILED = 94u,
	STEAM_RESULT_ACCOUNT_LIMIT_EXCEEDED = 95u,
	STEAM_RESULT_ACCOUNT_ACTIVITY_LIMIT_EXCEEDED = 96u,
	STEAM_RESULT_PHONE_ACTIVITY_LIMIT_EXCEEDED = 97u,
	STEAM_RESULT_REFUND_TO_WALLET = 98u,
	STEAM_RESULT_EMAIL_SEND_FAILURE = 99u,
	STEAM_RESULT_NOT_SETTLED = 100u,
	STEAM_RESULT_NEED_CAPTCHA = 101u,
	STEAM_RESULT_GSLT_DENIED = 102u,
	STEAM_RESULT_GS_OWNER_DENIED = 103u,
	STEAM_RESULT_INVALID_ITEM_TYPE = 104u,
	STEAM_RESULT_IP_BANNED = 105u,
	STEAM_RESULT_GSLT_EXPIRED = 106u,
	STEAM_RESULT_INSUFFICIENT_FUNDS = 107u,
	STEAM_RESULT_TOO_MANY_PENDING = 108u
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
