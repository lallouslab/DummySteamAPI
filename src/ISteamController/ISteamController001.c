#include "ISteamController001.h"
#include "ISteamController_priv.h"

static const struct ISteamController001Vtbl ISteamController001_vtbl = {
	ISteamController_Init,
	ISteamController_Shutdown,
	ISteamController_RunFrame,
	ISteamController_GetControllerState,
	ISteamController_TriggerHapticPulse,
	ISteamController_SetOverrideMode
};

struct ISteamController *SteamController001(void)
{
	static struct ISteamControllerImpl impl;

	impl.base.vtbl = &ISteamController001_vtbl;

	return &impl.base;
}
