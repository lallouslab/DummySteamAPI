#include <string.h>

#include "utils.h"

#include "ISteamMatchmakingServers.h"
#include "ISteamMatchmakingServers_priv.h"
#include "ISteamMatchmakingServers001.h"
#include "ISteamMatchmakingServers002.h"

struct ISteamMatchmakingServers *SteamMatchmakingServers_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamMatchmakingServers *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_001, SteamMatchmakingServers001 },
		{ STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_002, SteamMatchmakingServers002 },
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

	WARN("Unable to find ISteamMatchmakingServers version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamMatchmakingServers *SteamMatchmakingServers(void)
{
	LOG_ENTER0("()");

	return SteamMatchmakingServers002();
}
