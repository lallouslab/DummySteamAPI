#ifndef ISTEAMMUSIC_PRIV_H
#define ISTEAMMUSIC_PRIV_H 1

#include "steam.h"

#include "ISteamMusic.h"

struct ISteamMusicImpl
{
	struct ISteamMusic base;
};

static inline struct ISteamMusicImpl *impl_from_ISteamMusic(struct ISteamMusic *iface) {
	return CONTAINER_OF(iface, struct ISteamMusicImpl, base);
}

#endif /* ISTEAMMUSIC_PRIV_H */
