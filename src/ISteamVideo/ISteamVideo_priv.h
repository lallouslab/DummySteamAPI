#ifndef ISTEAMVIDEO_PRIV_H
#define ISTEAMVIDEO_PRIV_H 1

#include "steam.h"

#include "ISteamVideo.h"

struct ISteamVideoImpl
{
	struct ISteamVideo base;
};

static inline struct ISteamVideoImpl *impl_from_ISteamVideo(struct ISteamVideo *iface) {
	return CONTAINER_OF(iface, struct ISteamVideoImpl, base);
}

#endif /* ISTEAMVIDEO_PRIV_H */
