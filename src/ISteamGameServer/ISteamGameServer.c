#include <inttypes.h>
#include <string.h>

#include "debug.h"
#include "steam.h"

#include "ISteamGameServer.h"
#include "ISteamGameServer_priv.h"
#include "ISteamGameServer011.h"
#include "ISteamGameServer012.h"

static const char *steam_game_server_version = NULL;

MEMBER steam_bool_t ISteamGameServer_InitGameServer(struct ISteamGameServer *iface, uint32_t game_ip, uint16_t game_port, uint16_t query_port, enum steam_game_server_flag flags, steam_app_id_t app_id, const char *version)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, game_ip = \"%#x\", game_port = %u, query_port = %u, flags = %#x, app_id = %u, version = \"%s\")", VOIDPTR(This), game_ip, game_port, query_port, flags, app_id, version);

	return STEAM_TRUE;
}

MEMBER void ISteamGameServer_SetProduct(struct ISteamGameServer *iface, const char *product)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, product = \"%s\")", VOIDPTR(This), product);
}

MEMBER void ISteamGameServer_SetGameDescription(struct ISteamGameServer *iface, const char *description)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, description = \"%s\")", VOIDPTR(This), description);
}

MEMBER void ISteamGameServer_SetModDir(struct ISteamGameServer *iface, const char *mod_dir)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, mod_dir = \"%s\")", VOIDPTR(This), mod_dir);
}

MEMBER void ISteamGameServer_SetDedicatedServer(struct ISteamGameServer *iface, steam_bool_t dedicated)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, dedicated = %u)", VOIDPTR(This), dedicated);
}

MEMBER void ISteamGameServer_LogOnAnonymous(struct ISteamGameServer* iface)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));
}

MEMBER void ISteamGameServer_LogOff(struct ISteamGameServer *iface)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));
}

MEMBER steam_bool_t ISteamGameServer_BSecure(struct ISteamGameServer *iface)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

MEMBER union CSteamID ISteamGameServer_GetSteamID(struct ISteamGameServer *iface)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);
	union CSteamID steam_id;

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	steam_id.bits.account_id = 0;
	steam_id.bits.account_instance = STEAM_ACCOUNT_INSTANCE_USER_DESKTOP;
	steam_id.bits.account_type = STEAM_ACCOUNT_TYPE_GAMESERVER;
	steam_id.bits.universe = STEAM_UNIVERSE_PUBLIC;

	return steam_id;
}

MEMBER void ISteamGameServer_SetMaxPlayerCount(struct ISteamGameServer *iface, int count)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, count = %d)", VOIDPTR(This), count);
}

MEMBER void ISteamGameServer_SetBotPlayerCount(struct ISteamGameServer *iface, int count)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, count = %d)", VOIDPTR(This), count);
}

MEMBER void ISteamGameServer_SetServerName(struct ISteamGameServer *iface, const char *name)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));
}

MEMBER void ISteamGameServer_SetMapName(struct ISteamGameServer *iface, const char *name)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, name = \"%s\")", VOIDPTR(This), debug_str(name));
}

MEMBER void ISteamGameServer_SetPasswordProtected(struct ISteamGameServer *iface, steam_bool_t protected)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, protected = %u)", VOIDPTR(This), protected);
}

MEMBER void ISteamGameServer_SetSpectatorPort(struct ISteamGameServer *iface, uint16_t port)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, port = %u)", VOIDPTR(This), port);
}

MEMBER void ISteamGameServer_SetKeyValue(struct ISteamGameServer *iface, const char *key, const char *value)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, key = \"%s\", value = \"%s\")", VOIDPTR(This), debug_str(key), debug_str(value));
}

MEMBER void ISteamGameServer_SetGameTags(struct ISteamGameServer *iface, const char *tags)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, tags = \"%s\")", VOIDPTR(This), debug_str(tags));
}

MEMBER void ISteamGameServer_CreateUnauthenticatedUserConnection(union CSteamID *ret, struct ISteamGameServer *iface)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(ret = %p, This = %p)", VOIDPTR(ret), VOIDPTR(This));

	ret->bits.account_id = 1;
	ret->bits.account_instance = STEAM_ACCOUNT_INSTANCE_USER_DESKTOP;
	ret->bits.account_type = STEAM_ACCOUNT_TYPE_ANONGAMESERVER;
	ret->bits.universe = STEAM_UNIVERSE_INTERNAL;
}

MEMBER void ISteamGameServer_SendUserDisconnect(struct ISteamGameServer *iface, union CSteamID steam_id_user)
{
	struct ISteamGameServerImpl *This = impl_from_ISteamGameServer(iface);

	LOG_ENTER_NOTIMPL("(This = %p, steam_id_user = %#" PRIx64 ")", VOIDPTR(This), steam_id_user.raw);
}

MEMBER void ISteamGameServer_EnableHeartbeats(struct ISteamGameServer *iface, steam_bool_t enabled)
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
