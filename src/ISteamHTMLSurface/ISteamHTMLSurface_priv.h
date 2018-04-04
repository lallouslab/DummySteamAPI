#ifndef ISTEAMHTMLSURFACE_PRIV_H
#define ISTEAMHTMLSURFACE_PRIV_H 1

#include "steam.h"

#include "ISteamHTMLSurface.h"

struct ISteamHTMLSurfaceImpl
{
	struct ISteamHTMLSurface base;
};

static inline struct ISteamHTMLSurfaceImpl *impl_from_ISteamHTMLSurface(struct ISteamHTMLSurface *iface) {
	return CONTAINER_OF(iface, struct ISteamHTMLSurfaceImpl, base);
}

#endif /* ISTEAMHTMLSURFACE_PRIV_H */
