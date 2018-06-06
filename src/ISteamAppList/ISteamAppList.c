#include <string.h>

#include "debug.h"

#include "ISteamAppList.h"
#include "ISteamAppList_priv.h"
#include "ISteamAppList001.h"

static const char *steam_app_list_version = NULL;

MEMBER uint32_t ISteamAppList_GetNumInstalledApps(struct ISteamAppList *iface)
{
	struct ISteamAppListImpl *This = impl_from_ISteamAppList(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

MEMBER uint32_t ISteamAppList_GetInstalledApps(struct ISteamAppList *iface, steam_app_id_t *app_ids, uint32_t max_app_ids)
{
	struct ISteamAppListImpl *This = impl_from_ISteamAppList(iface);

	LOG_ENTER_NOTIMPL("(This = %p, app_ids = %p, max_app_ids = %" PRIu32 ")", VOIDPTR(This), VOIDPTR(app_ids), max_app_ids);

	return 0;
}

MEMBER int ISteamAppList_GetAppName(struct ISteamAppList *iface, steam_app_id_t app_id, char *name, int max_name_size)
{
	struct ISteamAppListImpl *This = impl_from_ISteamAppList(iface);

	LOG_ENTER_NOTIMPL("(This = %p, app_id = %u, name = %p, max_name_size = %d)", VOIDPTR(This), app_id, VOIDPTR(name), max_name_size);

	return -1;
}

MEMBER int ISteamAppList_GetAppInstallDir(struct ISteamAppList *iface, steam_app_id_t app_id, char *path, int max_path_size)
{
	struct ISteamAppListImpl *This = impl_from_ISteamAppList(iface);

	LOG_ENTER_NOTIMPL("(This = %p, app_id = %u, path = %p, max_path_size = %d)", VOIDPTR(This), app_id, VOIDPTR(path), max_path_size);

	return -1;
}

MEMBER int ISteamAppList_GetAppBuildId(struct ISteamAppList *iface, steam_app_id_t app_id)
{
	struct ISteamAppListImpl *This = impl_from_ISteamAppList(iface);

	LOG_ENTER_NOTIMPL("(This = %p, app_id = %u)", VOIDPTR(This), app_id);

	return 0;
}

struct ISteamAppList *SteamAppList_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamAppList *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMAPPLIST_INTERFACE_VERSION_001, SteamAppList001 },
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

	WARN("Unable to find ISteamAppList version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamAppList_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_app_list_version)
		steam_app_list_version = version;
}

EXPORT struct ISteamAppList *SteamAppList(void)
{
	static struct ISteamAppList *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_app_list_version)
	{
		steam_app_list_version = STEAMAPPLIST_INTERFACE_VERSION_001;

		WARN("ISteamAppList: No version specified, defaulting to \"%s\".", debug_str(steam_app_list_version));
	}

	if (!cached_iface)
		cached_iface = SteamAppList_generic(steam_app_list_version);

	return cached_iface;
}
