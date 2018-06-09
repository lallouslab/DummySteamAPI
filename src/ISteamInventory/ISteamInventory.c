#include <string.h>

#include "debug.h"

#include "ISteamInventory.h"
#include "ISteamInventory_priv.h"
#include "ISteamInventory001.h"
#include "ISteamInventory002.h"

static const char *steam_inventory_version = NULL;

struct ISteamInventory *SteamInventory_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamInventory *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMINVENTORY_INTERFACE_VERSION_001, SteamInventory001 },
		{ STEAMINVENTORY_INTERFACE_VERSION_002, SteamInventory002 },
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

	WARN("Unable to find ISteamInventory version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamInventory_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_inventory_version)
		steam_inventory_version = version;
}

EXPORT struct ISteamInventory *SteamInventory(void)
{
	static struct ISteamInventory *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_inventory_version)
	{
		steam_inventory_version = STEAMINVENTORY_INTERFACE_VERSION_002;

		WARN("ISteamInventory: No version specified, defaulting to \"%s\".", debug_str(steam_inventory_version));
	}

	if (!cached_iface)
		cached_iface = SteamInventory_generic(steam_inventory_version);

	return cached_iface;
}
