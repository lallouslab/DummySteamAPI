#ifndef ISTEAMREMOTESTORAGE_PRIV_H
#define ISTEAMREMOTESTORAGE_PRIV_H 1

#include "steam.h"

#include "ISteamRemoteStorage.h"

struct ISteamRemoteStorageImpl
{
	struct ISteamRemoteStorage base;
};

static inline struct ISteamRemoteStorageImpl *impl_from_ISteamRemoteStorage(struct ISteamRemoteStorage *iface) {
	return CONTAINER_OF(iface, struct ISteamRemoteStorageImpl, base);
}

MEMBER steam_bool_t ISteamRemoteStorage_FileWrite(struct ISteamRemoteStorage *iface, const char *filename, const void *data, int32_t size);
MEMBER int32_t ISteamRemoteStorage_GetFileSize(struct ISteamRemoteStorage *iface, const char *filename);
MEMBER int32_t ISteamRemoteStorage_GetFileCount(struct ISteamRemoteStorage *iface);
MEMBER steam_bool_t ISteamRemoteStorage_GetQuota(struct ISteamRemoteStorage *iface, int32_t *total_bytes, int32_t *available_bytes);
MEMBER void ISteamRemoteStorage_SetCloudEnabledForApp(struct ISteamRemoteStorage *iface, steam_bool_t enabled);

#endif /* ISTEAMREMOTESTORAGE_PRIV_H */
