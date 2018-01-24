#include "utils.h"

#include "ISteamNetworking001.h"
#include "ISteamNetworking_priv.h"

static const struct ISteamNetworking001 ISteamNetworking001_vtbl = {
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

struct ISteamNetworkingImpl *SteamNetworking001(void)
{
	static struct ISteamNetworkingImpl impl;

	impl.iface = &ISteamNetworking001_vtbl;

	return &impl;
}
