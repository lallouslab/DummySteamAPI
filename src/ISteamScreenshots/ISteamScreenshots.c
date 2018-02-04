#include <string.h>

#include "utils.h"

#include "ISteamScreenshots.h"
#include "ISteamScreenshots_priv.h"
#include "ISteamScreenshots001.h"

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

EXPORT struct ISteamScreenshots *SteamScreenshots(void)
{
	LOG_ENTER0("()");

	return SteamScreenshots001();
}
