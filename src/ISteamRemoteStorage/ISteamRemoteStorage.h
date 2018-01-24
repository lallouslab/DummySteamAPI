#ifndef ISTEAMREMOTESTORAGE_H
#define ISTEAMREMOTESTORAGE_H 1

#define STEAMREMOTESTORAGE_INTERFACE_VERSION_PREFIX "STEAMREMOTESTORAGE_INTERFACE_VERSION"

struct ISteamRemoteStorageImpl;

struct ISteamRemoteStorageImpl *SteamRemoteStorage_generic(const char *version);
extern struct ISteamRemoteStorageImpl *SteamRemoteStorage(void);

#endif /* ISTEAMREMOTESTORAGE_H */
