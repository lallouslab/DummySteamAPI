#include <string.h>

#include "debug.h"
#include "steam.h"

#include "ISteamScreenshots.h"
#include "ISteamScreenshots_priv.h"
#include "ISteamScreenshots001.h"
#include "ISteamScreenshots002.h"

static const char *steam_screenshots_version = NULL;

steam_bool_t ISteamScreenshots_HookScreenshots(struct ISteamScreenshots *iface, steam_bool_t enable)
{
	struct ISteamScreenshotsImpl *This = impl_from_ISteamScreenshots(iface);

	LOG_ENTER_NOTIMPL("(This = %p, enable = %d)", VOIDPTR(This), enable);

	return STEAM_TRUE;
}

struct ISteamScreenshots *SteamScreenshots_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamScreenshots *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMSCREENSHOTS_INTERFACE_VERSION_001, SteamScreenshots001 },
		{ STEAMSCREENSHOTS_INTERFACE_VERSION_002, SteamScreenshots002 },
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

	WARN("Unable to find ISteamScreenshots version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamScreenshots_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_screenshots_version)
		steam_screenshots_version = version;
}

EXPORT struct ISteamScreenshots *SteamScreenshots(void)
{
	static struct ISteamScreenshots *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_screenshots_version)
	{
		steam_screenshots_version = STEAMSCREENSHOTS_INTERFACE_VERSION_002;

		WARN("ISteamScreenshots: No version specified, defaulting to \"%s\".", debug_str(steam_screenshots_version));
	}

	if (!cached_iface)
		cached_iface = SteamScreenshots_generic(steam_screenshots_version);

	return cached_iface;
}
