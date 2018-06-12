#include <string.h>

#include "debug.h"
#include "steam.h"

#include "ISteamGameCoordinator.h"
#include "ISteamGameCoordinator_priv.h"
#include "ISteamGameCoordinator001.h"

static const char *steam_game_coordinator_version = NULL;

MEMBER enum steam_game_coordinator_result ISteamGameCoordinator_SendMessage(struct ISteamGameCoordinator *iface, uint32_t msg_type, const void *msg, uint32_t msg_size)
{
	struct ISteamGameCoordinatorImpl *This = impl_from_ISteamGameCoordinator(iface);

	LOG_ENTER_NOTIMPL("(This = %p, msg_type = %u, msg = %p, msg_size = %u)", VOIDPTR(This), msg_type, msg, msg_size);

	return STEAM_GAME_COORDINATOR_RESULT_INVALID_MESSAGE;
}

MEMBER steam_bool_t ISteamGameCoordinator_IsMessageAvailable(struct ISteamGameCoordinator *iface, uint32_t *msg_size)
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

	WARN("Unable to find ISteamGameCoordinator version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamGameCoordinator_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_game_coordinator_version)
		steam_game_coordinator_version = version;
}

EXPORT struct ISteamGameCoordinator *SteamGameCoordinator(void)
{
	static struct ISteamGameCoordinator*cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_game_coordinator_version)
	{
		steam_game_coordinator_version = STEAMGAMECOORDINATOR_INTERFACE_VERSION_001;

		WARN("ISteamGameCoordinator: No version specified, defaulting to \"%s\".", debug_str(steam_game_coordinator_version));
	}

	if (!cached_iface)
		cached_iface = SteamGameCoordinator_generic(steam_game_coordinator_version);

	return cached_iface;
}
