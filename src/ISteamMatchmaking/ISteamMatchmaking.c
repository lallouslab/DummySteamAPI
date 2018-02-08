#include <string.h>

#include "utils.h"

#include "ISteamMatchmaking.h"
#include "ISteamMatchmaking_priv.h"
#include "ISteamMatchmaking001.h"
#include "ISteamMatchmaking009.h"

static const char *steam_matchmaking_version = NULL;

int ISteamMatchmaking_GetFavoriteGameCount(struct ISteamMatchmaking *iface)
{
	struct ISteamMatchmakingImpl *This = impl_from_ISteamMatchmaking(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

struct ISteamMatchmaking *SteamMatchmaking_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamMatchmaking *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMMATCHMAKING_INTERFACE_VERSION_001, SteamMatchmaking001 },
		{ STEAMMATCHMAKING_INTERFACE_VERSION_009, SteamMatchmaking009 },
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

	WARN("Unable to find ISteamMatchmaking version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamMatchmaking_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_matchmaking_version)
		steam_matchmaking_version = version;
}

EXPORT struct ISteamMatchmaking *SteamMatchmaking(void)
{
	LOG_ENTER0("()");

	if (!steam_matchmaking_version)
	{
		steam_matchmaking_version = STEAMMATCHMAKING_INTERFACE_VERSION_009;

		WARN("ISteamMatchmaking: No version specified, defaulting to \"%s\".", debug_str(steam_matchmaking_version));
	}

	return SteamMatchmaking_generic(steam_matchmaking_version);
}
