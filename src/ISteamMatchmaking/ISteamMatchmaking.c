#include <string.h>

#include "CCallback.h"
#include "callbacks.h"
#include "debug.h"
#include "steam.h"

#include "ISteamMatchmaking.h"
#include "ISteamMatchmaking_priv.h"
#include "ISteamMatchmaking001.h"
#include "ISteamMatchmaking009.h"

static const char *steam_matchmaking_version = NULL;

MEMBER int ISteamMatchmaking_GetFavoriteGameCount(struct ISteamMatchmaking *iface)
{
	struct ISteamMatchmakingImpl *This = impl_from_ISteamMatchmaking(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 0;
}

MEMBER void ISteamMatchmaking_AddRequestLobbyListResultCountFilter(struct ISteamMatchmaking *iface, int max_results)
{
	struct ISteamMatchmakingImpl *This = impl_from_ISteamMatchmaking(iface);

	LOG_ENTER_NOTIMPL("(This = %p, filter = %d)", VOIDPTR(This), max_results);
}

MEMBER void ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter(struct ISteamMatchmaking *iface, union CSteamID steam_id_lobby)
{
	struct ISteamMatchmakingImpl *This = impl_from_ISteamMatchmaking(iface);

	LOG_ENTER_NOTIMPL("(This = %p, steam_id_lobby = %#" PRIx64 ")", VOIDPTR(This), steam_id_lobby.raw);
}

MEMBER steam_api_call_t ISteamMatchmaking_CreateLobby007(struct ISteamMatchmaking *iface, enum steam_lobby_type type, int max_members)
{
	struct ISteamMatchmakingImpl *This = impl_from_ISteamMatchmaking(iface);
	struct steam_callback_data_matchmaking_lobby_created lobby_created;

	LOG_ENTER_NOTIMPL("(This = %p, type = %u, max_members = %d)", VOIDPTR(This), type, max_members);

	lobby_created.result = STEAM_RESULT_FAIL;
	lobby_created.steam_id_lobby.raw = 0;

	return callbacks_dispatch_api_call_result_output(STEAM_CALLBACK_TYPE_MATCHMAKING_LOBBY_CREATED, STEAM_FALSE, &lobby_created, sizeof(lobby_created));
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
	static struct ISteamMatchmaking *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_matchmaking_version)
	{
		steam_matchmaking_version = STEAMMATCHMAKING_INTERFACE_VERSION_009;

		WARN("ISteamMatchmaking: No version specified, defaulting to \"%s\".", debug_str(steam_matchmaking_version));
	}

	if (!cached_iface)
		cached_iface = SteamMatchmaking_generic(steam_matchmaking_version);

	return cached_iface;
}
