#include "utils.h"

#include "ISteamHTTP002.h"
#include "ISteamHTTP_priv.h"

static const struct ISteamHTTP002 ISteamHTTP002_vtbl = {
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

struct ISteamHTTPImpl *SteamHTTP002(void)
{
	static struct ISteamHTTPImpl impl;

	impl.iface = &ISteamHTTP002_vtbl;

	return &impl;
}
