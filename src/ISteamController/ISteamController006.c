#include "macros.h"

#include "ISteamController006.h"
#include "ISteamController_priv.h"

static const struct ISteamController006Vtbl ISteamController006_vtbl = {
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
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamController *SteamController006(void)
{
	static struct ISteamControllerImpl impl;

	impl.base.vtbl.v006 = &ISteamController006_vtbl;

	return &impl.base;
}
