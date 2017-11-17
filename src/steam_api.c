#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "steam.h"

steam_bool_t SteamAPI_Init(void)
{
	return STEAM_TRUE;
}

void SteamAPI_Shutdown(void)
{

}

steam_bool_t SteamAPI_RestartAppIfNecessary(steam_app_id_t app_id)
{
	(void)app_id;

	/* The app was started through the Steam client. */
	return STEAM_FALSE;
}

void SteamAPI_RunCallbacks(void)
{

}
