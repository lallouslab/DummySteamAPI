#include <string.h>

#include "utils.h"

#include "ISteamNetworking.h"
#include "ISteamNetworking_priv.h"
#include "ISteamNetworking001.h"
#include "ISteamNetworking005.h"

static const char *steam_networking_version = NULL;

steam_bool_t ISteamNetworking_ReadP2PPacket(struct ISteamNetworking *iface, void *pub_dest, uint32_t cub_dest, uint32_t *cub_msg_size, void /* CSteamID */ **steam_id_remote, int nchannels)
{
	struct ISteamNetworkingImpl *This = impl_from_ISteamNetworking(iface);

	LOG_ENTER_NOTIMPL("(This = %p, pub_dest = %p, cub_dest = %u, cub_msg_size = %p, steam_id_remote = %p, nchannels = %d)", VOIDPTR(This), pub_dest, cub_dest, VOIDPTR(cub_msg_size), VOIDPTR(steam_id_remote), nchannels);

	*cub_msg_size = 0;
	*steam_id_remote = INVAL_PTR;

	return STEAM_FALSE;
}

steam_bool_t ISteamNetworking_AllowP2PPacketRelay(struct ISteamNetworking *iface, steam_bool_t allow)
{
	struct ISteamNetworkingImpl *This = impl_from_ISteamNetworking(iface);

	LOG_ENTER_NOTIMPL("(This = %p, allow = %u)", VOIDPTR(This), allow);

	return STEAM_TRUE;
}

struct ISteamNetworking *SteamNetworking_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamNetworking *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMNETWORKING_INTERFACE_VERSION_001, SteamNetworking001 },
		{ STEAMNETWORKING_INTERFACE_VERSION_005, SteamNetworking005 },
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

	WARN("Unable to find ISteamNetworking version \"%s\".\n", debug_str(version));

	return INVAL_PTR;
}

void SteamNetworking_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_networking_version)
		steam_networking_version = version;
}

EXPORT struct ISteamNetworking *SteamNetworking(void)
{
	static struct ISteamNetworking *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_networking_version)
	{
		steam_networking_version = STEAMNETWORKING_INTERFACE_VERSION_005;

		WARN("ISteamNetworking: No version specified, defaulting to \"%s\".", debug_str(steam_networking_version));
	}

	if (!cached_iface)
		cached_iface = SteamNetworking_generic(steam_networking_version);

	return cached_iface;
}
