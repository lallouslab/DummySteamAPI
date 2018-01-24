#ifndef ISTEAMUNIFIEDMESSAGES_H
#define ISTEAMUNIFIEDMESSAGES_H 1

struct ISteamUnifiedMessagesImpl;

#define STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_PREFIX "STEAMUNIFIEDMESSAGES_INTERFACE_VERSION"

struct ISteamUnifiedMessagesImpl *SteamUnifiedMessages_generic(const char *version);
extern struct ISteamUnifiedMessagesImpl *SteamUnifiedMessages(void);

#endif /* ISTEAMUNIFIEDMESSAGES_H */
