#ifndef ISTEAMSCREENSHOTS001_H
#define ISTEAMSCREENSHOTS001_H 1

#include "steam.h"

#include "ISteamScreenshots.h"

#define STEAMSCREENSHOTS_INTERFACE_VERSION_001 "STEAMSCREENSHOTS_INTERFACE_VERSION001"

struct ISteamScreenshots001Vtbl
{
	void *WriteScreenshot;
	void *AddScreenshotToLibrary;
	void *TriggerScreenshot;
	MEMBER steam_bool_t (*HookScreenshots)(struct ISteamScreenshots *iface, steam_bool_t enable);
	void *SetLocation;
	void *TagUser;
};

struct ISteamScreenshots *SteamScreenshots001(void);

#endif /* ISTEAMSCREENSHOTS001_H */
