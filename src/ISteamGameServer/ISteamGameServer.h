#ifndef ISTEAMGAMESERVER_H
#define ISTEAMGAMESERVER_H 1

#include "steam.h"

#define STEAMGAMESERVER_INTERFACE_VERSION_PREFIX "SteamGameServer"

struct ISteamGameServer
{
	union
	{
		const void *ptr;
		const struct ISteamGameServer011Vtbl *v011;
		const struct ISteamGameServer012Vtbl *v012;
	} vtbl;
};

enum steam_game_server_deny_reason
{
	STEAM_GAME_SERVER_DENY_REASON_INVALID = 0u,
	STEAM_GAME_SERVER_DENY_REASON_INVALID_VERSION = 1u,
	STEAM_GAME_SERVER_DENY_REASON_GENERIC = 2u,
	STEAM_GAME_SERVER_DENY_REASON_NOT_LOGGED_ON = 3u,
	STEAM_GAME_SERVER_DENY_REASON_NO_LICENSE = 4u,
	STEAM_GAME_SERVER_DENY_REASON_CHEATER = 5u,
	STEAM_GAME_SERVER_DENY_REASON_LOGGED_IN_ELSEWHERE = 6u,
	STEAM_GAME_SERVER_DENY_REASON_UNKNOWN_TEXT = 7u,
	STEAM_GAME_SERVER_DENY_REASON_INCOMPATIBLE_ANTI_CHEAT = 8u,
	STEAM_GAME_SERVER_DENY_REASON_MEMORY_CORRUPTION = 9u,
	STEAM_GAME_SERVER_DENY_REASON_INCOMPATIBLE_SOFTWARE = 10u,
	STEAM_GAME_SERVER_DENY_REASON_STEAM_CONNECTION_LOST = 11u,
	STEAM_GAME_SERVER_DENY_REASON_STEAM_CONNECTION_ERROR = 12u,
	STEAM_GAME_SERVER_DENY_REASON_STEAM_RESPONSE_TIMEDOUT = 13u,
	STEAM_GAME_SERVER_DENY_REASON_STEAM_VALIDATION_STALLED = 14u,
	STEAM_GAME_SERVER_DENY_REASON_STEAM_OWNER_LEFT_GUEST_USER = 15u
};

enum steam_game_server_flag
{
	STEAM_GAME_SERVER_FLAG_NONE       = 0u,
	STEAM_GAME_SERVER_FLAG_ACTIVE     = 1u << 0,
	STEAM_GAME_SERVER_FLAG_SECURE     = 1u << 1,
	STEAM_GAME_SERVER_FLAG_DEDICATED  = 1u << 2,
	STEAM_GAME_SERVER_FLAG_LINUX      = 1u << 3,
	STEAM_GAME_SERVER_FLAG_PASSWORDED = 1u << 4,
	STEAM_GAME_SERVER_FLAG_PRIVATE    = 1u << 5
};

PACKED_STRUCT steam_callback_data_game_server_client_approve
{
	union CSteamID steam_id;
	union CSteamID owner_steam_id;
};

PACKED_STRUCT steam_callback_data_game_server_client_deny
{
	union CSteamID steam_id;
	enum steam_game_server_deny_reason reason;
	char opt_reason_msg[128];
};

struct ISteamGameServer *SteamGameServer_generic(const char *version);
void SteamGameServer_set_version(const char *version);
extern struct ISteamGameServer *SteamGameServer(void);

#endif /* ISTEAMGAMESERVER_H */
