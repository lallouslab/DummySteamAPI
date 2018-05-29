#ifndef ISTEAMMATCHMAKING_H
#define ISTEAMMATCHMAKING_H 1

#define STEAMMATCHMAKING_INTERFACE_VERSION_PREFIX "SteamMatchMaking"

struct ISteamMatchmaking
{
	union
	{
		const void *ptr;
		const struct ISteamMatchmaking001Vtbl *v001;
		const struct ISteamMatchmaking009Vtbl *v009;
	} vtbl;
};

enum steam_matchmaking_lobby_comparison
{
	STEAM_MATCHMAKING_LOBBY_COMPARISON_LE = -2,
	STEAM_MATCHMAKING_LOBBY_COMPARISON_LT = -1,
	STEAM_MATCHMAKING_LOBBY_COMPARISON_EQ = 0,
	STEAM_MATCHMAKING_LOBBY_COMPARISON_GT = 1,
	STEAM_MATCHMAKING_LOBBY_COMPARISON_GE = 2,
	STEAM_MATCHMAKING_LOBBY_COMPARISON_NE = 3
};

enum steam_matchmaking_lobby_distance_filter
{
	STEAM_MATCHMAKING_LOBBY_DISTANCE_FILTER_CLOSE = 0u,
	STEAM_MATCHMAKING_LOBBY_DISTANCE_FILTER_DEFAULT = 1u,
	STEAM_MATCHMAKING_LOBBY_DISTANCE_FILTER_FAR = 2u,
	STEAM_MATCHMAKING_LOBBY_DISTANCE_FILTER_WORLDWIDE = 3u
};

PACKED_STRUCT steam_callback_data_matchmaking_lobby_created
{
	enum steam_result result;
	union CSteamID steam_id_lobby;
};

struct ISteamMatchmaking *SteamMatchmaking_generic(const char *version);
void SteamMatchmaking_set_version(const char *version);
extern struct ISteamMatchmaking *SteamMatchmaking(void);

#endif /* ISTEAMMATCHMAKING_H */
