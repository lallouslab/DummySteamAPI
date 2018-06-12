#ifndef ISTEAMGAMECOORDINATOR_H
#define ISTEAMGAMECOORDINATOR_H 1

#define STEAMGAMECOORDINATOR_INTERFACE_VERSION_PREFIX "SteamGameCoordinator"

struct ISteamGameCoordinator
{
	union
	{
		const void *ptr;
		const struct ISteamGameCoordinator001Vtbl *v001;
	} vtbl;
};

enum steam_game_coordinator_result
{
	STEAM_GAME_COORDINATOR_RESULT_OK = 0u,
	STEAM_GAME_COORDINATOR_RESULT_NO_MESSAGE = 1u,
	STEAM_GAME_COORDINATOR_RESULT_BUFFER_TOO_SMALL = 2u,
	STEAM_GAME_COORDINATOR_RESULT_NOT_LOGGED_ON = 3u,
	STEAM_GAME_COORDINATOR_RESULT_INVALID_MESSAGE = 4u
};

struct ISteamGameCoordinator *SteamGameCoordinator_generic(const char *version);
void SteamGameCoordinator_set_version(const char *version);
extern struct ISteamGameCoordinator *SteamGameCoordinator(void);

#endif /* ISTEAMGAMECOORDINATOR_H */
