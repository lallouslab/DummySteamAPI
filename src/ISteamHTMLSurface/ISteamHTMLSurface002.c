#include "macros.h"

#include "ISteamHTMLSurface002.h"
#include "ISteamHTMLSurface_priv.h"

static const struct ISteamHTMLSurface002Vtbl ISteamHTMLSurface002_vtbl = {
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

struct ISteamHTMLSurface *SteamHTMLSurface002(void)
{
	static struct ISteamHTMLSurfaceImpl impl;

	impl.base.vtbl.v002 = &ISteamHTMLSurface002_vtbl;

	return &impl.base;
}
