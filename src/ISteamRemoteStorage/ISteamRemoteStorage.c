#include <string.h>

#include "utils.h"

#include "ISteamRemoteStorage.h"
#include "ISteamRemoteStorage_priv.h"
#include "ISteamRemoteStorage001.h"
#include "ISteamRemoteStorage012.h"

steam_bool_t ISteamRemoteStorage_FileWrite(struct ISteamRemoteStorage *iface, const char *filename, const void *data, int32_t size)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p, filename = %s, data = %p, size = %" PRIu32 ")", VOIDPTR(This), debug_str(filename), data, size);

	return STEAM_FALSE;
}

int32_t ISteamRemoteStorage_GetFileSize(struct ISteamRemoteStorage *iface, const char *filename)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p, filename = %s)", VOIDPTR(This), debug_str(filename));

	return 0;
}

int32_t ISteamRemoteStorage_GetFileCount(struct ISteamRemoteStorage *iface)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

steam_bool_t ISteamRemoteStorage_GetQuota(struct ISteamRemoteStorage *iface, int32_t *total_bytes, int32_t *available_bytes)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p, total_bytes = %p, available_bytes = %p)", VOIDPTR(This), VOIDPTR(total_bytes), VOIDPTR(available_bytes));

	*total_bytes = 0;
	*available_bytes = 0;

	return STEAM_TRUE;
}

void ISteamRemoteStorage_SetCloudEnabledForApp(struct ISteamRemoteStorage *iface, steam_bool_t enabled)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p, enabled = %d)", VOIDPTR(This), enabled);
}

struct ISteamRemoteStorage *SteamRemoteStorage_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamRemoteStorage *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMREMOTESTORAGE_INTERFACE_VERSION_001, SteamRemoteStorage001 },
		{ STEAMREMOTESTORAGE_INTERFACE_VERSION_012, SteamRemoteStorage012 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = %s)", version);

	i = 0;
	while (ifaces[i].name)
	{
		if (strcmp(ifaces[i].name, version) == 0)
		{
			if (ifaces[i].iface_getter)
				return ifaces[i].iface_getter();

			break;
		}
		i++;
	}

	WARN("Unable to find ISteamRemoteStorage version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamRemoteStorage *SteamRemoteStorage(void)
{
	LOG_ENTER0("()");

	return SteamRemoteStorage012();
}
