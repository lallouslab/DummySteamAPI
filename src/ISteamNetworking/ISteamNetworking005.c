#include "utils.h"

#include "ISteamNetworking005.h"
#include "ISteamNetworking_priv.h"

static const struct ISteamNetworking005 ISteamNetworking005_vtbl = {
	INVAL_PTR,
	INVAL_PTR,
	ISteamNetworking_ReadP2PPacket,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamNetworking_AllowP2PPacketRelay,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamNetworkingImpl *SteamNetworking005(void)
{
	static struct ISteamNetworkingImpl impl;

	impl.iface = &ISteamNetworking005_vtbl;

	return &impl;
}
