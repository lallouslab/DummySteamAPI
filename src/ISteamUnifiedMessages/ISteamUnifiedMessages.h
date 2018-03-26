#ifndef ISTEAMUNIFIEDMESSAGES_H
#define ISTEAMUNIFIEDMESSAGES_H 1

struct ISteamUnifiedMessages
{
	union
	{
		const void *ptr;
		const struct ISteamUnifiedMessages001Vtbl *v001;
	} vtbl;
};

#define STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_PREFIX "STEAMUNIFIEDMESSAGES_INTERFACE_VERSION"

struct ISteamUnifiedMessages *SteamUnifiedMessages_generic(const char *version);
void SteamUnifiedMessages_set_version(const char *version);
extern struct ISteamUnifiedMessages *SteamUnifiedMessages(void);

#endif /* ISTEAMUNIFIEDMESSAGES_H */
