#include "utils.h"

#include "ISteamHTTP002.h"
#include "ISteamHTTP_priv.h"

static const struct ISteamHTTP002Vtbl ISteamHTTP002_vtbl = {
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

struct ISteamHTTP *SteamHTTP002(void)
{
	static struct ISteamHTTPImpl impl;

	impl.base.vtbl.v002 = &ISteamHTTP002_vtbl;

	return &impl.base;
}
