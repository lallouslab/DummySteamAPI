#ifndef ISTEAMFRIENDS_H
#define ISTEAMFRIENDS_H 1

#define STEAMFRIENDS_INTERFACE_VERSION_PREFIX "SteamFriends"

struct ISteamFriends
{
	union
	{
		const void *ptr;
		const struct ISteamFriends001Vtbl *v001;
		const struct ISteamFriends014Vtbl *v014;
		const struct ISteamFriends015Vtbl *v015;
	} vtbl;
};

struct ISteamFriends *SteamFriends_generic(const char *version);
void SteamFriends_set_version(const char *version);
extern struct ISteamFriends *SteamFriends(void);

#endif /* ISTEAMFRIENDS_H */
