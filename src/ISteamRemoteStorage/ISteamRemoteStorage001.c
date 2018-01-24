#include "utils.h"

#include "ISteamRemoteStorage001.h"
#include "ISteamRemoteStorage_priv.h"

static const struct ISteamRemoteStorage001 ISteamRemoteStorage001_vtbl = {
	INVAL_PTR,
	ISteamRemoteStorage_GetFileSize,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamRemoteStorage_GetQuota
};

struct ISteamRemoteStorageImpl *SteamRemoteStorage001(void)
{
	static struct ISteamRemoteStorageImpl impl;

	impl.iface = &ISteamRemoteStorage001_vtbl;

	return &impl;
}
