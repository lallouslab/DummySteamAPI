#ifndef ISTEAMHTTP_PRIV_H
#define ISTEAMHTTP_PRIV_H 1

#include "steam.h"

#include "ISteamHTTP.h"

struct ISteamHTTPImpl
{
	struct ISteamHTTP base;
};

static inline struct ISteamHTTPImpl *impl_from_ISteamHTTP(struct ISteamHTTP *iface) {
	return CONTAINER_OF(iface, struct ISteamHTTPImpl, base);
}

extern struct ISteamHTTP *SteamHTTP(void);

#endif /* ISTEAMHTTP_PRIV_H */
