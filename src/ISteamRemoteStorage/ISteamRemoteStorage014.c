#include "macros.h"

#include "ISteamRemoteStorage014.h"
#include "ISteamRemoteStorage_priv.h"

static const struct ISteamRemoteStorage014Vtbl ISteamRemoteStorage014_vtbl = {
	ISteamRemoteStorage_FileWrite,
	ISteamRemoteStorage_FileRead,
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
	ISteamRemoteStorage_FileWriteStreamCancel,
	ISteamRemoteStorage_FileExists,
	INVAL_PTR,
	ISteamRemoteStorage_GetFileSize,
	INVAL_PTR,
	INVAL_PTR,
	ISteamRemoteStorage_GetFileCount,
	INVAL_PTR,
	ISteamRemoteStorage014_GetQuota,
	ISteamRemoteStorage_IsCloudEnabledForAccount,
	ISteamRemoteStorage_IsCloudEnabledForApp,
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

struct ISteamRemoteStorage *SteamRemoteStorage014(void)
{
	static struct ISteamRemoteStorageImpl impl;

	impl.base.vtbl.v014 = &ISteamRemoteStorage014_vtbl;

	return &impl.base;
}
