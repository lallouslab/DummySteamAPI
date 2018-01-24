#ifndef ISTEAMREMOTESTORAGE001_H
#define ISTEAMREMOTESTORAGE001_H 1

#include "steam.h"

#include "ISteamRemoteStorage.h"

#define STEAMREMOTESTORAGE_INTERFACE_VERSION_001 "STEAMREMOTESTORAGE_INTERFACE_VERSION001"

struct ISteamRemoteStorage001
{
	void *FileWrite;
	int32_t (*GetFileSize)(struct ISteamRemoteStorageImpl *This, const char *filename);
	void *FileRead;
	void *FileExists;
	void *FileDelete;
	void *GetFileCount;
	void *GetFileNameAndSize;
	steam_bool_t (*GetQuota)(struct ISteamRemoteStorageImpl *This, int32_t *total_bytes, int32_t *available_bytes);
};

struct ISteamRemoteStorageImpl *SteamRemoteStorage001(void);

#endif /* ISTEAMREMOTESTORAGE001_H */
