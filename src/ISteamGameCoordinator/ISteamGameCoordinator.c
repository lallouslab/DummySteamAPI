#include <stdio.h>
#include <string.h>

#include "utils.h"

#include "ISteamGameCoordinator.h"
#include "ISteamGameCoordinator_priv.h"
#include "ISteamGameCoordinator001.h"

steam_bool_t ISteamGameCoordinator_IsMessageAvailable(struct ISteamGameCoordinatorImpl *This, uint32_t *msg_size)
{
	LOG_ENTER_NOTIMPL("(This = %p, msg_size = %p)", VOIDPTR(This), VOIDPTR(msg_size));

	*msg_size = 0;

	return STEAM_FALSE;
}

struct ISteamGameCoordinatorImpl *SteamGameCoordinator_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamGameCoordinatorImpl *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMGAMECOORDINATOR_INTERFACE_VERSION_001, SteamGameCoordinator001 },
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

	WARN("Unable to find ISteamGameCoordinator version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamGameCoordinatorImpl *SteamGameCoordinator(void)
{
	LOG_ENTER0("()");

	return SteamGameCoordinator001();
}
