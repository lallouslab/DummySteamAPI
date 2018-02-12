#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "debug.h"
#include "utils.h"
#include "steam.h"

#include "ISteamClient/ISteamClient.h"
#include "steam_gameserver.h"

EXPORT struct ISteamClient *g_pSteamClientGameServer = INVAL_PTR;

EXPORT steam_bool_t SteamGameServer_Init(uint32_t ip, uint16_t steam_port, uint16_t game_port, uint16_t query_port, enum steam_game_server_mode server_mode, const char *version)
{
	LOG_ENTER_NOTIMPL("(ip = %#x, steam_port = %u, game_port = %u, query_port = %u, server_mode = %u, version = \"%s\")", ip, steam_port, game_port, query_port, server_mode, debug_str(version));

	g_pSteamClientGameServer = SteamClient();

	return STEAM_TRUE;
}

EXPORT steam_bool_t SteamGameServer_InitSafe(uint32_t ip, uint16_t steam_port, uint16_t game_port, uint16_t query_port, enum steam_game_server_mode server_mode, const char *version)
{
	LOG_ENTER_NOTIMPL("(ip = %#x, steam_port = %u, game_port = %u, query_port = %u, server_mode = %u, version = \"%s\")", ip, steam_port, game_port, query_port, server_mode, debug_str(version));

	g_pSteamClientGameServer = SteamClient();

	return STEAM_TRUE;
}

EXPORT uint32_t SteamGameServer_GetIPCCallCount(void)
{
	LOG_ENTER0_NOTIMPL("()");

	return 1000;
}

EXPORT steam_handle_pipe_t SteamGameServer_GetHSteamPipe(void)
{
	LOG_ENTER0_NOTIMPL("()");

	return 1;
}

EXPORT steam_user_t SteamGameServer_GetHSteamUser(void)
{
	LOG_ENTER0_NOTIMPL("()");

	return 1;
}

EXPORT void SteamGameServer_Shutdown(void)
{
	LOG_ENTER0_NOTIMPL("()");
}

EXPORT void SteamGameServer_RunCallbacks(void)
{
	LOG_ENTER0_NOTIMPL("()");
}
