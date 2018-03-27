#include "macros.h"

#include "ISteamMusicRemote001.h"
#include "ISteamMusicRemote_priv.h"

static const struct ISteamMusicRemote001Vtbl ISteamMusicRemote001_vtbl = {
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

struct ISteamMusicRemote *SteamMusicRemote001(void)
{
	static struct ISteamMusicRemoteImpl impl;

	impl.base.vtbl.v001 = &ISteamMusicRemote001_vtbl;

	return &impl.base;
}
