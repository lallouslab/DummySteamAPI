#ifndef ISTEAMAPPLIST_H
#define ISTEAMAPPLIST_H 1

#define STEAMAPPLIST_INTERFACE_VERSION_PREFIX "STEAMAPPLIST_INTERFACE_VERSION"

struct ISteamAppList
{
	const void *vtbl;
};

struct ISteamAppList *SteamAppList_generic(const char *version);
void SteamAppList_set_version(const char *version);
extern struct ISteamAppList *SteamAppList(void);

#endif /* ISTEAMAPPLIST_H */
