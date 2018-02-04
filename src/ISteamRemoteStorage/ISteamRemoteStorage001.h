#ifndef ISTEAMREMOTESTORAGE001_H
#define ISTEAMREMOTESTORAGE001_H 1

#include "steam.h"

#include "ISteamRemoteStorage.h"

#define STEAMREMOTESTORAGE_INTERFACE_VERSION_001 "STEAMREMOTESTORAGE_INTERFACE_VERSION001"

struct ISteamRemoteStorage001Vtbl
{
	void *FileWrite;
	int32_t (*GetFileSize)(struct ISteamRemoteStorage *iface, const char *filename);
	void *FileRead;
	void *FileExists;
	void *FileDelete;
	void *GetFileCount;
	void *GetFileNameAndSize;
	steam_bool_t (*GetQuota)(struct ISteamRemoteStorage *iface, int32_t *total_bytes, int32_t *available_bytes);
};

static inline struct ISteamRemoteStorage001Vtbl *get_ISteamRemoteStorage001Vtbl_from_ISteamRemoteStorage(struct ISteamRemoteStorage *iface) {
	return (struct ISteamRemoteStorage001Vtbl *)iface->vtbl;
}

struct ISteamRemoteStorage *SteamRemoteStorage001(void);

#endif /* ISTEAMREMOTESTORAGE001_H */
