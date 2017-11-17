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

int SteamAPI_RestartAppIfNecessary(uint32_t unOwnAppID)
{
	(void)unOwnAppID;

	/* The app was started through the Steam client. */
	return 0;
}

void SteamAPI_RunCallbacks(void)
{

}
