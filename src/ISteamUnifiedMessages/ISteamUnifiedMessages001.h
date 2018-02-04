#ifndef ISTEAMUNIFIEDMESSAGES001_H
#define ISTEAMUNIFIEDMESSAGES001_H 1

#include "steam.h"

#include "ISteamUnifiedMessages.h"

#define STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_001 "STEAMUNIFIEDMESSAGES_INTERFACE_VERSION001"

struct ISteamUnifiedMessages001Vtbl
{
	void *SendMethod;
	void *GetMethodResponseInfo;
    void *GetMethodResponseData;
    void *ReleaseMethod;
	void *SendNotification;
};

static inline struct ISteamUnifiedMessages001Vtbl *get_ISteamUnifiedMessages001Vtbl_from_ISteamUnifiedMessages(struct ISteamUnifiedMessages *iface) {
	return (struct ISteamUnifiedMessages001Vtbl *)iface->vtbl;
}

struct ISteamUnifiedMessages *SteamUnifiedMessages001(void);

#endif /* ISTEAMUNIFIEDMESSAGES001_H */
