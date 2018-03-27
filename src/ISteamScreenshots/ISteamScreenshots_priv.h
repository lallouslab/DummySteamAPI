#ifndef ISTEAMSCREENSHOTS_PRIV_H
#define ISTEAMSCREENSHOTS_PRIV_H 1

#include "steam.h"

#include "ISteamScreenshots.h"

struct ISteamScreenshotsImpl
{
	struct ISteamScreenshots base;
};

static inline struct ISteamScreenshotsImpl *impl_from_ISteamScreenshots(struct ISteamScreenshots *iface) {
	return CONTAINER_OF(iface, struct ISteamScreenshotsImpl, base);
}

steam_bool_t ISteamScreenshots_HookScreenshots(struct ISteamScreenshots *iface, steam_bool_t enable);

#endif /* ISTEAMSCREENSHOTS_PRIV_H */
