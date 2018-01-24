#include <string.h>

#include "utils.h"

#include "ISteamScreenshots.h"
#include "ISteamScreenshots_priv.h"
#include "ISteamScreenshots001.h"

steam_bool_t ISteamScreenshots_HookScreenshots(struct ISteamScreenshotsImpl *This, steam_bool_t enable)
{
	LOG_ENTER_NOTIMPL("(This = %p, enable = %d)", VOIDPTR(This), enable);

	return STEAM_TRUE;
}

struct ISteamScreenshotsImpl *SteamScreenshots_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamScreenshotsImpl *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMSCREENSHOTS_INTERFACE_VERSION_001, SteamScreenshots001 },
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

	WARN("Unable to find ISteamScreenshots version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamScreenshotsImpl *SteamScreenshots(void)
{
	LOG_ENTER0("()");

	return SteamScreenshots001();
}
