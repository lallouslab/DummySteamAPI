#ifndef ISTEAMREMOTESTORAGE_H
#define ISTEAMREMOTESTORAGE_H 1

#define STEAMREMOTESTORAGE_INTERFACE_VERSION_PREFIX "STEAMREMOTESTORAGE_INTERFACE_VERSION"

struct ISteamRemoteStorage
{
	const void *vtbl;
};

struct ISteamRemoteStorage *SteamRemoteStorage_generic(const char *version);
extern struct ISteamRemoteStorage *SteamRemoteStorage(void);

#endif /* ISTEAMREMOTESTORAGE_H */
