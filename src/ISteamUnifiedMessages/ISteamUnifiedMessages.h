#ifndef ISTEAMUNIFIEDMESSAGES_H
#define ISTEAMUNIFIEDMESSAGES_H 1

struct ISteamUnifiedMessages
{
	const void *vtbl;
};

#define STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_PREFIX "STEAMUNIFIEDMESSAGES_INTERFACE_VERSION"

struct ISteamUnifiedMessages *SteamUnifiedMessages_generic(const char *version);
extern struct ISteamUnifiedMessages *SteamUnifiedMessages(void);

#endif /* ISTEAMUNIFIEDMESSAGES_H */
