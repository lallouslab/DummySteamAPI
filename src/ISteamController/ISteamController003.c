#include "macros.h"

#include "ISteamController003.h"
#include "ISteamController_priv.h"

static const struct ISteamController003Vtbl ISteamController003_vtbl = {
	ISteamController_Init003,
	ISteamController_Shutdown,
	ISteamController_RunFrame,
	ISteamController_GetConnectedControllers,
	INVAL_PTR,
	ISteamController_GetActionSetHandle,
	ISteamController_ActivateActionSet,
	INVAL_PTR,
	ISteamController_GetDigitalActionHandle,
	INVAL_PTR,
	INVAL_PTR,
	ISteamController_GetAnalogActionHandle,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamController *SteamController003(void)
{
	static struct ISteamControllerImpl impl;

	impl.base.vtbl.v003 = &ISteamController003_vtbl;

	return &impl.base;
}
