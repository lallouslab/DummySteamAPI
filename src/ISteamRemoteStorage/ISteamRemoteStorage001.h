#ifndef ISTEAMREMOTESTORAGE001_H
#define ISTEAMREMOTESTORAGE001_H 1

#include "steam.h"

#include "ISteamRemoteStorage.h"

#define STEAMREMOTESTORAGE_INTERFACE_VERSION_001 "STEAMREMOTESTORAGE_INTERFACE_VERSION001"

struct ISteamRemoteStorage001Vtbl
{
	void *FileWrite;
	MEMBER int32_t (*GetFileSize)(struct ISteamRemoteStorage *iface, const char *filename);
	void *FileRead;
	void *FileExists;
	void *FileDelete;
	void *GetFileCount;
	void *GetFileNameAndSize;
	MEMBER steam_bool_t (*GetQuota)(struct ISteamRemoteStorage *iface, int32_t *total_bytes, int32_t *available_bytes);
};

struct ISteamRemoteStorage *SteamRemoteStorage001(void);

#endif /* ISTEAMREMOTESTORAGE001_H */
