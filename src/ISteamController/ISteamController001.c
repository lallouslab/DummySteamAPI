#include "ISteamController001.h"
#include "ISteamController_priv.h"

static const struct ISteamController001 ISteamController001_vtbl = {
	ISteamController_Init,
	ISteamController_Shutdown,
	ISteamController_RunFrame,
	ISteamController_GetControllerState,
	ISteamController_TriggerHapticPulse,
	ISteamController_SetOverrideMode
};

struct ISteamControllerImpl *SteamController001(void)
{
	static struct ISteamControllerImpl impl;

	impl.iface = &ISteamController001_vtbl;

	return &impl;
}
