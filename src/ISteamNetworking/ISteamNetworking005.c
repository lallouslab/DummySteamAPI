#include "macros.h"

#include "ISteamNetworking005.h"
#include "ISteamNetworking_priv.h"

static const struct ISteamNetworking005Vtbl ISteamNetworking005_vtbl = {
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

struct ISteamNetworking *SteamNetworking005(void)
{
	static struct ISteamNetworkingImpl impl;

	impl.base.vtbl.v005 = &ISteamNetworking005_vtbl;

	return &impl.base;
}
