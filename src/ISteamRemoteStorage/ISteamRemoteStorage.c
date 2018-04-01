#include <string.h>

#include "debug.h"
#include "steam.h"

#include "ISteamRemoteStorage.h"
#include "ISteamRemoteStorage_priv.h"
#include "ISteamRemoteStorage001.h"
#include "ISteamRemoteStorage012.h"
#include "ISteamRemoteStorage013.h"

static const char *steam_remote_storage_version = NULL;

MEMBER steam_bool_t ISteamRemoteStorage_FileWrite(struct ISteamRemoteStorage *iface, const char *filename, const void *data, int32_t size)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p, filename = \"%s\", data = %p, size = %" PRIu32 ")", VOIDPTR(This), debug_str(filename), data, size);

	return STEAM_FALSE;
}

MEMBER int32_t ISteamRemoteStorage_GetFileSize(struct ISteamRemoteStorage *iface, const char *filename)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p, filename = \"%s\")", VOIDPTR(This), debug_str(filename));

	return 0;
}

MEMBER int32_t ISteamRemoteStorage_GetFileCount(struct ISteamRemoteStorage *iface)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

MEMBER steam_bool_t ISteamRemoteStorage_GetQuota(struct ISteamRemoteStorage *iface, int32_t *total_bytes, int32_t *available_bytes)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p, total_bytes = %p, available_bytes = %p)", VOIDPTR(This), VOIDPTR(total_bytes), VOIDPTR(available_bytes));

	*total_bytes = 0;
	*available_bytes = 0;

	return STEAM_TRUE;
}

MEMBER void ISteamRemoteStorage_SetCloudEnabledForApp(struct ISteamRemoteStorage *iface, steam_bool_t enabled)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p, enabled = %d)", VOIDPTR(This), enabled);
}

MEMBER steam_api_call_t ISteamRemoteStorage_EnumeratePublishedFilesByUserAction(struct ISteamRemoteStorage *iface, enum steam_workshop_file_action action, uint32_t start_idx)
{
	struct ISteamRemoteStorageImpl *This = impl_from_ISteamRemoteStorage(iface);

	LOG_ENTER_NOTIMPL("(This = %p, action = %u, start_idx = %u)", VOIDPTR(This), action, start_idx);

	return 0;
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
		{ STEAMREMOTESTORAGE_INTERFACE_VERSION_013, SteamRemoteStorage013 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = \"%s\")", debug_str(version));

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

	WARN("Unable to find ISteamRemoteStorage version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamRemoteStorage_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_remote_storage_version)
		steam_remote_storage_version = version;
}

EXPORT struct ISteamRemoteStorage *SteamRemoteStorage(void)
{
	static struct ISteamRemoteStorage *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_remote_storage_version)
	{
		steam_remote_storage_version = STEAMREMOTESTORAGE_INTERFACE_VERSION_013;

		WARN("ISteamRemoteStorage: No version specified, defaulting to \"%s\".", debug_str(steam_remote_storage_version));
	}

	if (!cached_iface)
		cached_iface = SteamRemoteStorage_generic(steam_remote_storage_version);

	return cached_iface;
}
