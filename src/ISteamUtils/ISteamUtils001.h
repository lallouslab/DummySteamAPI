#ifndef ISTEAMUTILS001_H
#define ISTEAMUTILS001_H 1

#include "steam.h"

#include "ISteamUtils.h"

#define STEAMUTILS_INTERFACE_VERSION_001 "SteamUtils001"

struct ISteamUtils001
{
	uint32_t (*GetSecondsSinceAppActive)(struct ISteamUtilsImpl *This);
	void *GetSecondsSinceComputerActive;
	enum steam_universe (*GetConnectedUniverse)(struct ISteamUtilsImpl *This);
	void *GetServerRealTime;
	void *GetIPCountry;
	void *GetImageSize;
	void *GetImageRGBA;
};

struct ISteamUtilsImpl *SteamUtils001(void);

#endif /* ISTEAMUTILS001_H */
