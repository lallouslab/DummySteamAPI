#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int SteamAPI_Init(void)
{
	return 1;
}

void SteamAPI_Shutdown(void)
{

}

int SteamAPI_RestartAppIfNecessary(steam_app_id_t app_id)
{
	(void)app_id;

	/* The app was started through the Steam client. */
	return 0;
}

void SteamAPI_RunCallbacks(void)
{

}
