#include <inttypes.h>
#include <string.h>

#include "debug.h"
#include "utils.h"

#include "ISteamGameServer.h"
#include "ISteamGameServer_priv.h"
#include "ISteamGameServer011.h"
#include "ISteamGameServer012.h"

static const char *steam_game_server_version = NULL;

steam_bool_t ISteamGameServer_InitGameServer(struct ISteamGameServer *iface, uint32_t game_ip, uint16_t game_port, uint16_t query_port, enum steam_game_server_flag flags, steam_app_id_t app_id, const char *version)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, game_ip = \"%#x\", game_port = %u, query_port = %u, flags = %#x, app_id = %u, version = \"%s\")", VOIDPTR(This), game_ip, game_port, query_port, flags, app_id, version);

	return STEAM_TRUE;
}

void ISteamGameServer_SetMapName(struct ISteamGameServer *iface, const char *name)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));
}

void ISteamGameServer_SetPasswordProtected(struct ISteamGameServer *iface, steam_bool_t protected)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, protected = %u)", VOIDPTR(This), protected);
}

void ISteamGameServer_SetKeyValue(struct ISteamGameServer *iface, const char *key, const char *value)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, key = \"%s\", value = \"%s\")", VOIDPTR(This), debug_str(key), debug_str(value));
}

void ISteamGameServer_SetGameTags(struct ISteamGameServer *iface, const char *tags)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, tags = \"%s\")", VOIDPTR(This), debug_str(tags));
}

void ISteamGameServer_CreateUnauthenticatedUserConnection(union CSteamID *ret, struct ISteamGameServer *iface)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(ret = %p, This = %p)", VOIDPTR(ret), VOIDPTR(This));

	ret->bits.account_id = 1;
	ret->bits.account_instance = STEAM_ACCOUNT_INSTANCE_USER_DESKTOP;
	ret->bits.account_type = STEAM_ACCOUNT_TYPE_ANONGAMESERVER;
	ret->bits.universe = STEAM_UNIVERSE_INTERNAL;
}

void ISteamGameServer_SendUserDisconnect(struct ISteamGameServer *iface, union CSteamID steam_id_user)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, steam_id_user = %#" PRIx64 ")", VOIDPTR(This), steam_id_user.raw);
}

void ISteamGameServer_EnableHeartbeats(struct ISteamGameServer *iface, steam_bool_t enabled)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, enabled = %u)", VOIDPTR(This), enabled);
}

struct ISteamGameServer *SteamGameServer_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamGameServer *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMGAMESERVER_INTERFACE_VERSION_011, SteamGameServer011 },
		{ STEAMGAMESERVER_INTERFACE_VERSION_012, SteamGameServer012 },
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

	WARN("Unable to find ISteamGameServer version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamGameServer_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_game_server_version)
		steam_game_server_version = version;
}

EXPORT struct ISteamGameServer *SteamGameServer(void)
{
	static struct ISteamGameServer *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_game_server_version)
	{
		steam_game_server_version = STEAMGAMESERVER_INTERFACE_VERSION_012;

		WARN("ISteamGameServer: No version specified, defaulting to \"%s\".", debug_str(steam_game_server_version));
	}

	if (!cached_iface)
		cached_iface = SteamGameServer_generic(steam_game_server_version);

	return cached_iface;
}
