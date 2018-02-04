#ifndef ISTEAMSCREENSHOTS002_H
#define ISTEAMSCREENSHOTS002_H 1

#include "steam.h"

#include "ISteamScreenshots.h"

#define STEAMSCREENSHOTS_INTERFACE_VERSION_002 "STEAMSCREENSHOTS_INTERFACE_VERSION002"

struct ISteamScreenshots002Vtbl
{
	void *WriteScreenshot;
	void *AddScreenshotToLibrary;
	void *TriggerScreenshot;
	steam_bool_t (*HookScreenshots)(struct ISteamScreenshots *iface, steam_bool_t enable);
	void *SetLocation;
	void *TagUser;
	void *TagPublishedFile;
};

static inline struct ISteamScreenshots002Vtbl *get_ISteamScreenshots002Vtbl_from_ISteamScreenshots(struct ISteamScreenshots *iface) {
	return (struct ISteamScreenshots002Vtbl *)iface->vtbl;
}

struct ISteamScreenshots *SteamScreenshots002(void);

#endif /* ISTEAMSCREENSHOTS002_H */
