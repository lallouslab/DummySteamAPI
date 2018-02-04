#include <string.h>

#include "utils.h"

#include "ISteamGameCoordinator.h"
#include "ISteamGameCoordinator_priv.h"
#include "ISteamGameCoordinator001.h"

steam_bool_t ISteamGameCoordinator_IsMessageAvailable(struct ISteamGameCoordinator *iface, uint32_t *msg_size)
{
	struct ISteamGameCoordinatorImpl *This = impl_from_ISteamGameCoordinator(iface);

	LOG_ENTER_NOTIMPL("(This = %p, msg_size = %p)", VOIDPTR(This), VOIDPTR(msg_size));

	*msg_size = 0;

	return STEAM_FALSE;
}

struct ISteamGameCoordinator *SteamGameCoordinator_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamGameCoordinator *(*iface_getter)(void);
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

EXPORT struct ISteamGameCoordinator *SteamGameCoordinator(void)
{
	LOG_ENTER0("()");

	return SteamGameCoordinator001();
}
