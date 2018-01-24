#ifndef STEAM_GAMESERVER_H
#define STEAM_GAMESERVER_H 1

#include <stdint.h>

#include "steam.h"

#include "ISteamClient/ISteamClient.h"

enum steam_game_server_mode
{
	STEAM_GAME_SERVER_MODE_INVALID = 0,
	STEAM_GAME_SERVER_MODE_NO_AUTH = 1,
	STEAM_GAME_SERVER_MODE_AUTH = 2,
	STEAM_GAME_SERVER_MODE_SECAUTH = 3
}; 

extern struct ISteamClient *g_pSteamClientGameServer;

#endif /* STEAM_GAMESERVER_H */
