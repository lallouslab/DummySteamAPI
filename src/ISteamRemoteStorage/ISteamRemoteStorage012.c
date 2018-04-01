#include "macros.h"

#include "ISteamRemoteStorage012.h"
#include "ISteamRemoteStorage_priv.h"

static const struct ISteamRemoteStorage012Vtbl ISteamRemoteStorage012_vtbl = {
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
	ISteamRemoteStorage_EnumerateUserPublishedFiles,
	INVAL_PTR,
	ISteamRemoteStorage_EnumerateUserSubscribedFiles,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamRemoteStorage_EnumeratePublishedFilesByUserAction,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamRemoteStorage *SteamRemoteStorage012(void)
{
	static struct ISteamRemoteStorageImpl impl;

	impl.base.vtbl.v012 = &ISteamRemoteStorage012_vtbl;

	return &impl.base;
}
