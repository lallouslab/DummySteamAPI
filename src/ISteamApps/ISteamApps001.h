#ifndef ISTEAMAPPS001_H
#define ISTEAMAPPS001_H 1

#include "ISteamApps.h"

#define STEAMAPPS_INTERFACE_VERSION_001 "STEAMAPPS_INTERFACE_VERSION001"

struct ISteamApps001Vtbl
{
	void *GetAppData;
};

struct ISteamApps *SteamApps001(void);

#endif /* ISTEAMAPPS001_H */
