#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "steam.h"
#include "utils.h"

steam_bool_t SteamAPI_Init(void)
{
	log_enter0("()");

	return STEAM_TRUE;
}

void SteamAPI_Shutdown(void)
{
	log_enter0("()");
}

steam_bool_t SteamAPI_RestartAppIfNecessary(steam_app_id_t app_id)
{
	log_enter("(app_id = %u)", app_id);

	/* The app was started through the Steam client. */
	return STEAM_FALSE;
}

void SteamAPI_RunCallbacks(void)
{
#if 0
	/* Too noisy. */
	log_enter0("()");
#endif
}
