#ifndef ISTEAMGAMECOORDINATOR_H
#define ISTEAMGAMECOORDINATOR_H 1

#define STEAMGAMECOORDINATOR_INTERFACE_VERSION_PREFIX "SteamGameCoordinator"

struct ISteamGameCoordinatorImpl;

struct ISteamGameCoordinatorImpl *SteamGameCoordinator_generic(const char *version);
extern struct ISteamGameCoordinatorImpl *SteamGameCoordinator(void);

#endif /* ISTEAMGAMECOORDINATOR_H */
