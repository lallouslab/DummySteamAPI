#ifndef ISTEAMGAMECOORDINATOR_H
#define ISTEAMGAMECOORDINATOR_H 1

#define STEAMGAMECOORDINATOR_INTERFACE_VERSION_PREFIX "SteamGameCoordinator"

struct ISteamGameCoordinator
{
	union
	{
		const void *ptr;
		const struct ISteamGameCoordinator001Vtbl *v001;
	} vtbl;
};

struct ISteamGameCoordinator *SteamGameCoordinator_generic(const char *version);
void SteamGameCoordinator_set_version(const char *version);
extern struct ISteamGameCoordinator *SteamGameCoordinator(void);

#endif /* ISTEAMGAMECOORDINATOR_H */
