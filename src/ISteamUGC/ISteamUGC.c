#include <string.h>

#include "debug.h"
#include "steam.h"

#include "ISteamUGC.h"
#include "ISteamUGC_priv.h"
#include "ISteamUGC001.h"
#include "ISteamUGC005.h"
#include "ISteamUGC007.h"
#include "ISteamUGC010.h"

static const char *steam_ugc_version = NULL;

MEMBER uint32_t ISteamUGC_GetNumSubscribedItems(struct ISteamUGC *iface)
{
	struct ISteamUGCImpl *This = impl_from_ISteamUGC(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

struct ISteamUGC *SteamUGC_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUGC *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUGC_INTERFACE_VERSION_001, SteamUGC001 },
		{ STEAMUGC_INTERFACE_VERSION_005, SteamUGC005 },
		{ STEAMUGC_INTERFACE_VERSION_007, SteamUGC007 },
		{ STEAMUGC_INTERFACE_VERSION_010, SteamUGC010 },
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

	WARN("Unable to find ISteamUGC version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamUGC_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_ugc_version)
		steam_ugc_version = version;
}

EXPORT struct ISteamUGC *SteamUGC(void)
{
	static struct ISteamUGC *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_ugc_version)
	{
		steam_ugc_version = STEAMUGC_INTERFACE_VERSION_010;

		WARN("ISteamUGC: No version specified, defaulting to \"%s\".", debug_str(steam_ugc_version));
	}

	if (!cached_iface)
		cached_iface = SteamUGC_generic(steam_ugc_version);

	return cached_iface;
}
