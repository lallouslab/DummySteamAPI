#ifndef ISTEAMUNIFIEDMESSAGES001_H
#define ISTEAMUNIFIEDMESSAGES001_H 1

#include "steam.h"

#include "ISteamUnifiedMessages.h"

#define STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_001 "STEAMUNIFIEDMESSAGES_INTERFACE_VERSION001"

struct ISteamUnifiedMessages001
{
	void *SendMethod;
	void *GetMethodResponseInfo;
    void *GetMethodResponseData;
    void *ReleaseMethod;
	void *SendNotification;
};

struct ISteamUnifiedMessagesImpl *SteamUnifiedMessages001(void);

#endif /* ISTEAMUNIFIEDMESSAGES001_H */
