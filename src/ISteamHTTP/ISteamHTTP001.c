#include "macros.h"

#include "ISteamHTTP001.h"
#include "ISteamHTTP_priv.h"

static const struct ISteamHTTP001Vtbl ISteamHTTP001_vtbl = {
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

struct ISteamHTTP *SteamHTTP001(void)
{
	static struct ISteamHTTPImpl impl;

	impl.base.vtbl.v001 = &ISteamHTTP001_vtbl;

	return &impl.base;
}
