#ifndef CCALLBACK_H
#define CCALLBACK_H 1

#include "steam.h"

enum steam_callback_type
{
	/* 100 */
	STEAM_CALLBACK_TYPE_USER = 100u,
	STEAM_CALLBACK_TYPE_USER_STEAM_SERVERS_CONNECTED          = STEAM_CALLBACK_TYPE_USER + 1u,
	STEAM_CALLBACK_TYPE_USER_STEAM_SERVERS_CONNECT_FAILURE    = STEAM_CALLBACK_TYPE_USER + 2u,
	STEAM_CALLBACK_TYPE_USER_STEAM_SERVERS_DISCONNECTED       = STEAM_CALLBACK_TYPE_USER + 3u,
	STEAM_CALLBACK_TYPE_USER_BEGIN_LOGON_RETRY                = STEAM_CALLBACK_TYPE_USER + 4u,
	STEAM_CALLBACK_TYPE_USER_CLIENT_GAME_SERVER_DENY          = STEAM_CALLBACK_TYPE_USER + 13u,
	STEAM_CALLBACK_TYPE_USER_PRIMARY_CHAT_DESTINATION_SET_OLD = STEAM_CALLBACK_TYPE_USER + 14u,
	STEAM_CALLBACK_TYPE_USER_GS_POLICY_RESPONSE               = STEAM_CALLBACK_TYPE_USER + 15u,
	STEAM_CALLBACK_TYPE_USER_IPC_FAILURE                      = STEAM_CALLBACK_TYPE_USER + 17u,
	STEAM_CALLBACK_TYPE_USER_LICENSES_UPDATED                 = STEAM_CALLBACK_TYPE_USER + 25u,
	STEAM_CALLBACK_TYPE_USER_APP_LIFETIME_NOTICE              = STEAM_CALLBACK_TYPE_USER + 30u,
	STEAM_CALLBACK_TYPE_USER_DRM_SDK_FILE_TRANSFER_RESULT     = STEAM_CALLBACK_TYPE_USER + 41u,
	STEAM_CALLBACK_TYPE_USER_VALIDATE_AUTH_TICKET_RESPONSE    = STEAM_CALLBACK_TYPE_USER + 43u,
	STEAM_CALLBACK_TYPE_USER_MICRO_TXN_AUTHORIZATION_RESPONSE = STEAM_CALLBACK_TYPE_USER + 52u,
	STEAM_CALLBACK_TYPE_USER_ENCRYPTED_APP_TICKET_RESPONSE    = STEAM_CALLBACK_TYPE_USER + 54u,
	STEAM_CALLBACK_TYPE_USER_GET_AUTH_SESSION_TICKET_RESPONSE = STEAM_CALLBACK_TYPE_USER + 63u,
	STEAM_CALLBACK_TYPE_USER_GAME_WEB_CALLBACK                = STEAM_CALLBACK_TYPE_USER + 64u,
	STEAM_CALLBACK_TYPE_USER_STORE_AUTH_URL_RESPONSE          = STEAM_CALLBACK_TYPE_USER + 65u,

	/* 200 */
	STEAM_CALLBACK_TYPE_GAME_SERVER = STEAM_CALLBACK_TYPE_USER + 100u,

	/* 300 */
	STEAM_CALLBACK_TYPE_FRIENDS = STEAM_CALLBACK_TYPE_GAME_SERVER + 100u,
	STEAM_CALLBACK_TYPE_FRIENDS_PERSONA_STATE_CHANGE              = STEAM_CALLBACK_TYPE_FRIENDS + 4u,
	STEAM_CALLBACK_TYPE_FRIENDS_GAME_OVERLAY_ACTIVATED            = STEAM_CALLBACK_TYPE_FRIENDS + 31u,
	STEAM_CALLBACK_TYPE_FRIENDS_GAME_SERVER_CHANGE_REQUESTED      = STEAM_CALLBACK_TYPE_FRIENDS + 32u,
	STEAM_CALLBACK_TYPE_FRIENDS_GAME_LOBBY_JOIN_REQUESTED         = STEAM_CALLBACK_TYPE_FRIENDS + 33u,
	STEAM_CALLBACK_TYPE_FRIENDS_AVATAR_IMAGE_LOADED               = STEAM_CALLBACK_TYPE_FRIENDS + 34u,
	STEAM_CALLBACK_TYPE_FRIENDS_CLAN_OFFICER_LIST_RESPONSE        = STEAM_CALLBACK_TYPE_FRIENDS + 35u,
	STEAM_CALLBACK_TYPE_FRIENDS_FRIEND_RICH_PRESENCE_UPDATE       = STEAM_CALLBACK_TYPE_FRIENDS + 36u,
	STEAM_CALLBACK_TYPE_FRIENDS_GAME_RICH_PRESENCE_JOIN_REQUESTED = STEAM_CALLBACK_TYPE_FRIENDS + 37u,

	/* 400 */
	STEAM_CALLBACK_TYPE_BILLING = STEAM_CALLBACK_TYPE_FRIENDS + 100u,

	/* 500 */
	STEAM_CALLBACK_TYPE_MATCHMAKING = STEAM_CALLBACK_TYPE_BILLING + 100u,

	/* 600 */
	STEAM_CALLBACK_TYPE_CONTENT_SERVER = STEAM_CALLBACK_TYPE_MATCHMAKING + 100u,

	/* 700 */
	STEAM_CALLBACK_TYPE_UTILS = STEAM_CALLBACK_TYPE_CONTENT_SERVER + 100u,
	STEAM_CALLBACK_TYPE_UTILS_IP_COUNTRY               = STEAM_CALLBACK_TYPE_UTILS + 1u,
	STEAM_CALLBACK_TYPE_UTILS_LOW_BATTERY_POWER        = STEAM_CALLBACK_TYPE_UTILS + 2u,
	STEAM_CALLBACK_TYPE_UTILS_STEAM_API_CALL_COMPLETED = STEAM_CALLBACK_TYPE_UTILS + 3u,
	STEAM_CALLBACK_TYPE_UTILS_STEAM_SHUTDOWN           = STEAM_CALLBACK_TYPE_UTILS + 4u,

	/* 800 */
	STEAM_CALLBACK_TYPE_CLIENT_FRIENDS = STEAM_CALLBACK_TYPE_UTILS + 100u,

	/* 900 */
	STEAM_CALLBACK_TYPE_CLIENT_USER = STEAM_CALLBACK_TYPE_CLIENT_FRIENDS + 100u,

	/* 1000 */
	STEAM_CALLBACK_TYPE_APPS = STEAM_CALLBACK_TYPE_CLIENT_USER + 100u,

	/* 1100 */
	STEAM_CALLBACK_TYPE_USER_STATS = STEAM_CALLBACK_TYPE_APPS + 100u,
	STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_RECEIVED = STEAM_CALLBACK_TYPE_USER_STATS + 1u,
	STEAM_CALLBACK_TYPE_USER_STATS_USER_STATS_STORED   = STEAM_CALLBACK_TYPE_USER_STATS + 2u,

	/* 1200 */
	STEAM_CALLBACK_TYPE_NETWORKING                          = STEAM_CALLBACK_TYPE_USER_STATS + 100u,
	STEAM_CALLBACK_TYPE_NETWORKING_SOCKET_STATUS_CALLBACK   = STEAM_CALLBACK_TYPE_NETWORKING + 1u,
	STEAM_CALLBACK_TYPE_NETWORKING_P2P_SESSION_REQUEST      = STEAM_CALLBACK_TYPE_NETWORKING + 2u,
	STEAM_CALLBACK_TYPE_NETWORKING_P2P_SESSION_CONNECT_FAIL = STEAM_CALLBACK_TYPE_NETWORKING + 3u,

	STEAM_CALLBACK_TYPE_MAX
};

enum steam_callback_flags
{
	STEAM_CALLBACK_FLAGS_NONE        = 0u,
	STEAM_CALLBACK_FLAGS_REGISTERED  = 1u << 0,
	STEAM_CALLBACK_FLAGS_GAME_SERVER = 2u << 1
};

struct CCallbackBase;

typedef void (*steam_api_call_callback_t)(void *obj, void *param, steam_bool_t io_failure);
typedef void (*steam_callback_t)(void *obj, void *param);

struct CCallbackBaseVtbl
{
	MEMBER void (*Run0)(struct CCallbackBase *iface, void *param);
	MEMBER void (*Run1)(struct CCallbackBase *iface, steam_bool_t io_failure, steam_api_call_t api_call, void *param);
	MEMBER int (*GetCallbackSizeBytes)(struct CCallbackBase *iface);
};

struct CCallbackBase
{
	const struct CCallbackBaseVtbl *vtbl;
	enum steam_callback_flags flags : 8;
	enum steam_callback_type type;
};

struct CCallResult
{
	struct CCallbackBase base;
	steam_api_call_t api_call;
	void *obj;
	MEMBER steam_api_call_callback_t callback;

	/* DSA-specific */
	size_t data_size;
};

struct CCallback
{
	struct CCallbackBase base;
	void *obj;
	MEMBER steam_callback_t callback;

	/* DSA-specific */
	size_t data_size;
};

struct CCallbackManual
{
	struct CCallback base;
};

MEMBER static inline struct CCallResult *CCallResult_from_CCallbackBase(struct CCallbackBase *iface)
{
	return CONTAINER_OF(iface, struct CCallResult, base);
}

MEMBER static inline struct CCallback *CCallback_from_CCallbackBase(struct CCallbackBase *iface)
{
	return CONTAINER_OF(iface, struct CCallback, base);
}

MEMBER static inline struct CCallbackManual *CCallbackManual_from_CCallback(struct CCallback *iface)
{
	return CONTAINER_OF(iface, struct CCallbackManual, base);
}

MEMBER void CCallbackBase(struct CCallbackBase *iface);
MEMBER enum steam_callback_type CCallbackBase_GetICallback(struct CCallbackBase *iface);
MEMBER void CCallResult(struct CCallResult *iface, enum steam_callback_type type, size_t data_size);
MEMBER void CCallResult_dtor(struct CCallResult *iface);
MEMBER void CCallResult_Set(struct CCallResult *iface, steam_api_call_t api_call, void *obj, MEMBER_CALLBACK_PARAM steam_api_call_callback_t callback);
MEMBER steam_bool_t CCallResult_IsActive(struct CCallResult *iface);
MEMBER void CCallResult_Cancel(struct CCallResult *iface);
MEMBER void CCallback(struct CCallback *iface, void *obj, MEMBER_CALLBACK_PARAM steam_callback_t callback, size_t data_size, steam_bool_t is_game_server);
MEMBER void CCallback_dtor(struct CCallback *iface);
MEMBER void CCallback_Register(struct CCallback *iface, void *obj, MEMBER_CALLBACK_PARAM steam_callback_t callback);
MEMBER void CCallback_Unregister(struct CCallback *iface);
MEMBER void CCallback_SetGameserverFlag(struct CCallback *iface);
MEMBER void CCallbackManual(struct CCallbackManual *iface, size_t data_size, steam_bool_t is_game_server);
MEMBER void CCallbackManual_dtor(struct CCallbackManual *iface);

#endif /* CCALLBACK_H */
