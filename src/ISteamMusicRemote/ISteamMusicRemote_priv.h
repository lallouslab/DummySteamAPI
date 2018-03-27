#ifndef ISTEAMMUSICREMOTE_PRIV_H
#define ISTEAMMUSICREMOTE_PRIV_H 1

#include "steam.h"

#include "ISteamMusicRemote.h"

struct ISteamMusicRemoteImpl
{
	struct ISteamMusicRemote base;
};

static inline struct ISteamMusicRemoteImpl *impl_from_ISteamMusicRemote(struct ISteamMusicRemote *iface) {
	return CONTAINER_OF(iface, struct ISteamMusicRemoteImpl, base);
}

#endif /* ISTEAMMUSICREMOTE_PRIV_H */
