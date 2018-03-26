#include "utils.h"

#include "ISteamRemoteStorage001.h"
#include "ISteamRemoteStorage_priv.h"

static const struct ISteamRemoteStorage001Vtbl ISteamRemoteStorage001_vtbl = {
	INVAL_PTR,
	ISteamRemoteStorage_GetFileSize,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamRemoteStorage_GetQuota
};

struct ISteamRemoteStorage *SteamRemoteStorage001(void)
{
	static struct ISteamRemoteStorageImpl impl;

	impl.base.vtbl.v001 = &ISteamRemoteStorage001_vtbl;

	return &impl.base;
}
