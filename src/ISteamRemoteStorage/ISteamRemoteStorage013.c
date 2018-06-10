#include "macros.h"

#include "ISteamRemoteStorage013.h"
#include "ISteamRemoteStorage_priv.h"

static const struct ISteamRemoteStorage013Vtbl ISteamRemoteStorage013_vtbl = {
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
	INVAL_PTR,
	ISteamRemoteStorage_FileExists,
	INVAL_PTR,
	ISteamRemoteStorage_GetFileSize,
	INVAL_PTR,
	INVAL_PTR,
	ISteamRemoteStorage_GetFileCount,
	INVAL_PTR,
	ISteamRemoteStorage_GetQuota,
	INVAL_PTR,
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

struct ISteamRemoteStorage *SteamRemoteStorage013(void)
{
	static struct ISteamRemoteStorageImpl impl;

	impl.base.vtbl.v013 = &ISteamRemoteStorage013_vtbl;

	return &impl.base;
}
