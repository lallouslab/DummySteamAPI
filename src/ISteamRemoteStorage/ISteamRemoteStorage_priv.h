#ifndef ISTEAMREMOTESTORAGE_PRIV_H
#define ISTEAMREMOTESTORAGE_PRIV_H 1

#include "steam.h"

struct ISteamRemoteStorageImpl
{
	const void *iface;
};

steam_bool_t ISteamRemoteStorage_FileWrite(struct ISteamRemoteStorageImpl *This, const char *filename, const void *data, int32_t size);
int32_t ISteamRemoteStorage_GetFileSize(struct ISteamRemoteStorageImpl *This, const char *filename);
int32_t ISteamRemoteStorage_GetFileCount(struct ISteamRemoteStorageImpl *This);
steam_bool_t ISteamRemoteStorage_GetQuota(struct ISteamRemoteStorageImpl *This, int32_t *total_bytes, int32_t *available_bytes);
void ISteamRemoteStorage_SetCloudEnabledForApp(struct ISteamRemoteStorageImpl *This, steam_bool_t enabled);

#endif /* ISTEAMREMOTESTORAGE_PRIV_H */
