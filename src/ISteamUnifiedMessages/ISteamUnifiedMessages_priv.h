#ifndef ISTEAMUNIFIEDMESSAGES_PRIV_H
#define ISTEAMUNIFIEDMESSAGES_PRIV_H 1

#include "steam.h"
#include "utils.h"

#include "ISteamUnifiedMessages.h"

struct ISteamUnifiedMessagesImpl
{
	struct ISteamUnifiedMessages base;
};

static inline struct ISteamUnifiedMessagesImpl *impl_from_ISteamUnifiedMessages(struct ISteamUnifiedMessages *iface) {
	return CONTAINER_OF(iface, struct ISteamUnifiedMessagesImpl, base);
}

#endif /* ISTEAMUNIFIEDMESSAGES_PRIV_H */
