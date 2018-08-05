#include "macros.h"

#include "ISteamController005.h"
#include "ISteamController_priv.h"

static const struct ISteamController005Vtbl ISteamController005_vtbl = {
	ISteamController_Init003,
	ISteamController_Shutdown,
	ISteamController_RunFrame,
	ISteamController_GetConnectedControllers,
	INVAL_PTR,
	ISteamController_GetActionSetHandle,
	ISteamController_ActivateActionSet,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamController_GetAnalogActionHandle,
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

struct ISteamController *SteamController005(void)
{
	static struct ISteamControllerImpl impl;

	impl.base.vtbl.v005 = &ISteamController005_vtbl;

	return &impl.base;
}
