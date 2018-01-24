#ifndef ISTEAMSCREENSHOTS_PRIV_H
#define ISTEAMSCREENSHOTS_PRIV_H 1

#include "steam.h"

struct ISteamScreenshotsImpl
{
	const void *iface;
};

steam_bool_t ISteamScreenshots_HookScreenshots(struct ISteamScreenshotsImpl *This, steam_bool_t enable);

#endif /* ISTEAMSCREENSHOTS_PRIV_H */
