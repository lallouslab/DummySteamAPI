#include "utils.h"

#include "ISteamHTTP001.h"
#include "ISteamHTTP_priv.h"

static const struct ISteamHTTP001 ISteamHTTP001_vtbl = {
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
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamHTTPImpl *SteamHTTP001(void)
{
	static struct ISteamHTTPImpl impl;

	impl.iface = &ISteamHTTP001_vtbl;

	return &impl;
}
