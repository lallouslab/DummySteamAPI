#ifndef ISTEAMSCREENSHOTS003_H
#define ISTEAMSCREENSHOTS003_H 1

#include "steam.h"

#include "ISteamScreenshots.h"

#define STEAMSCREENSHOTS_INTERFACE_VERSION_003 "STEAMSCREENSHOTS_INTERFACE_VERSION003"

struct ISteamScreenshots003Vtbl
{
	void *WriteScreenshot;
	void *AddScreenshotToLibrary;
	void *TriggerScreenshot;
	MEMBER steam_bool_t (*HookScreenshots)(struct ISteamScreenshots *iface, steam_bool_t enable);
	void *SetLocation;
	void *TagUser;
	void *TagPublishedFile;
	void *IsScreenshotsHooked;
	void *AddVRScreenshotToLibrary;
};

struct ISteamScreenshots *SteamScreenshots003(void);

#endif /* ISTEAMSCREENSHOTS003_H */
