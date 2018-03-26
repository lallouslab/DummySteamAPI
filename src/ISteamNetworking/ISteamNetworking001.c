#include "utils.h"

#include "ISteamNetworking001.h"
#include "ISteamNetworking_priv.h"

static const struct ISteamNetworking001Vtbl ISteamNetworking001_vtbl = {
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

struct ISteamNetworking *SteamNetworking001(void)
{
	static struct ISteamNetworkingImpl impl;

	impl.base.vtbl.v001 = &ISteamNetworking001_vtbl;

	return &impl.base;
}
