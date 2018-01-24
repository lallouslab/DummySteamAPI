#include <stdio.h>
#include <string.h>

#include "utils.h"

#include "ISteamGameServerStats.h"
#include "ISteamGameServerStats_priv.h"
#include "ISteamGameServerStats001.h"

struct ISteamGameServerStatsImpl *SteamGameServerStats_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamGameServerStatsImpl *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMGAMESERVERSTATS_INTERFACE_VERSION_001, SteamGameServerStats001 },
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

	WARN("Unable to find ISteamGameServerStats version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamGameServerStatsImpl *SteamGameServerStats(void)
{
	LOG_ENTER0("()");

	return SteamGameServerStats001();
}
