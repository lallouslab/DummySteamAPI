#ifndef ISTEAMGAMECOORDINATOR_H
#define ISTEAMGAMECOORDINATOR_H 1

#define STEAMGAMECOORDINATOR_INTERFACE_VERSION_PREFIX "SteamGameCoordinator"

struct ISteamGameCoordinator
{
	const void *vtbl;
};

struct ISteamGameCoordinator *SteamGameCoordinator_generic(const char *version);
extern struct ISteamGameCoordinator *SteamGameCoordinator(void);

#endif /* ISTEAMGAMECOORDINATOR_H */
