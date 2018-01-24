#ifndef ISTEAMFRIENDS_H
#define ISTEAMFRIENDS_H 1

#define STEAMFRIENDS_INTERFACE_VERSION_PREFIX "SteamFriends"

struct ISteamFriendsImpl;

struct ISteamFriendsImpl *SteamFriends_generic(const char *version);
extern struct ISteamFriendsImpl *SteamFriends(void);

#endif /* ISTEAMFRIENDS_H */
