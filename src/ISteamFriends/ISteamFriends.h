#ifndef ISTEAMFRIENDS_H
#define ISTEAMFRIENDS_H 1

#define STEAMFRIENDS_INTERFACE_VERSION_PREFIX "SteamFriends"

struct ISteamFriends
{
	const void *vtbl;
};

struct ISteamFriends *SteamFriends_generic(const char *version);
extern struct ISteamFriends *SteamFriends(void);

#endif /* ISTEAMFRIENDS_H */
