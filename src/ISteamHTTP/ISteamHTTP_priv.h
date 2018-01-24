#ifndef ISTEAMHTTP_PRIV_H
#define ISTEAMHTTP_PRIV_H 1

#include <stdint.h>

#include "steam.h"

struct ISteamHTTPImpl
{
	const void *iface;
};

extern struct ISteamHTTPImpl *SteamHTTP(void);

#endif /* ISTEAMHTTP_PRIV_H */
