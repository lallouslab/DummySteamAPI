#ifndef ISTEAMREMOTESTORAGE_H
#define ISTEAMREMOTESTORAGE_H 1

#include "steam.h"

#define STEAMREMOTESTORAGE_INTERFACE_VERSION_PREFIX "STEAMREMOTESTORAGE_INTERFACE_VERSION"

struct ISteamRemoteStorage
{
	union
	{
		const void *ptr;
		const struct ISteamRemoteStorage001Vtbl *v001;
		const struct ISteamRemoteStorage012Vtbl *v012;
		const struct ISteamRemoteStorage013Vtbl *v013;
		const struct ISteamRemoteStorage014Vtbl *v014;
	} vtbl;
};

typedef uint64_t steam_published_file_id_t;

enum steam_workshop_file_action
{
	STEAM_WORKSHOP_FILE_ACTION_PLAYED = 0u,
	STEAM_WORKSHOP_FILE_ACTION_COMPLETED = 1u
};

struct ISteamRemoteStorage *SteamRemoteStorage_generic(const char *version);
void SteamRemoteStorage_set_version(const char *version);
extern struct ISteamRemoteStorage *SteamRemoteStorage(void);

#endif /* ISTEAMREMOTESTORAGE_H */
