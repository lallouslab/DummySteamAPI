#ifndef ISTEAMFRIENDS_H
#define ISTEAMFRIENDS_H

#include "steam.h"

struct ISteamFriendsImpl;

struct ISteamFriends
{
	const char *(*GetPersonaName)(struct ISteamFriendsImpl *This);
	steam_delayed_return_t (*SetPersonaName)(struct ISteamFriendsImpl *This, const char *name);
	uint32_t (*GetPersonaState)(struct ISteamFriendsImpl *This);
	int (*GetFriendCount)(struct ISteamFriendsImpl *This, int flags);
};

struct ISteamFriendsImpl *SteamFriends(void);

#endif
