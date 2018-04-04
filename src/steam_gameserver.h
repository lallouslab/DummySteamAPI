#ifndef STEAM_GAMESERVER_H
#define STEAM_GAMESERVER_H 1

#include "ISteamClient/ISteamClient.h"

enum steam_game_server_mode
{
	STEAM_GAME_SERVER_MODE_INVALID = 0,
	STEAM_GAME_SERVER_MODE_NO_AUTH = 1,
	STEAM_GAME_SERVER_MODE_AUTH = 2,
	STEAM_GAME_SERVER_MODE_SECAUTH = 3
};

extern struct ISteamClient *g_pSteamClientGameServer;

extern steam_bool_t SteamGameServer_Init(uint32_t ip, uint16_t steam_port, uint16_t game_port, uint16_t query_port, enum steam_game_server_mode server_mode, const char *version);
extern steam_bool_t SteamInternal_GameServer_Init(uint32_t ip, uint16_t steam_port, uint16_t game_port, uint16_t query_port, enum steam_game_server_mode server_mode, const char *version);
extern steam_bool_t SteamGameServer_InitSafe(uint32_t ip, uint16_t steam_port, uint16_t game_port, uint16_t query_port, enum steam_game_server_mode server_mode, const char *version);
extern uint32_t SteamGameServer_GetIPCCallCount(void);
extern steam_handle_pipe_t SteamGameServer_GetHSteamPipe(void);
extern steam_user_t SteamGameServer_GetHSteamUser(void);
extern steam_bool_t SteamGameServer_BSecure(void);
extern union CSteamID SteamGameServer_GetSteamID(void);
extern void SteamGameServer_Shutdown(void);
extern void SteamGameServer_RunCallbacks(void);

#endif /* STEAM_GAMESERVER_H */
