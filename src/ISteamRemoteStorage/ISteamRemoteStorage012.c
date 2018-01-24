#include "utils.h"

#include "ISteamRemoteStorage012.h"
#include "ISteamRemoteStorage_priv.h"

static const struct ISteamRemoteStorage012 ISteamRemoteStorage012_vtbl = {
	ISteamRemoteStorage_FileWrite,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamRemoteStorage_GetFileSize,
	INVAL_PTR,
	INVAL_PTR,
	ISteamRemoteStorage_GetFileCount,
	INVAL_PTR,
	ISteamRemoteStorage_GetQuota,
	INVAL_PTR,
	INVAL_PTR,
	ISteamRemoteStorage_SetCloudEnabledForApp,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamRemoteStorageImpl *SteamRemoteStorage012(void)
{
	static struct ISteamRemoteStorageImpl impl;

	impl.iface = &ISteamRemoteStorage012_vtbl;

	return &impl;
}
