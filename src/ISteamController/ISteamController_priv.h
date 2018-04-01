#ifndef ISTEAMCONTROLLER_PRIV_H
#define ISTEAMCONTROLLER_PRIV_H 1

#include "steam.h"

#include "ISteamController.h"

struct ISteamControllerImpl
{
	struct ISteamController base;
};

static inline struct ISteamControllerImpl *impl_from_ISteamController(struct ISteamController *iface) {
	return CONTAINER_OF(iface, struct ISteamControllerImpl, base);
}

MEMBER steam_bool_t ISteamController_Init(struct ISteamController *iface, const char *path_to_cfg);
MEMBER steam_bool_t ISteamController_Init003(struct ISteamController *iface);
MEMBER steam_bool_t ISteamController_Shutdown(struct ISteamController *iface);
MEMBER void ISteamController_RunFrame(struct ISteamController *iface);
MEMBER steam_bool_t ISteamController_GetControllerState(struct ISteamController *iface, uint32_t index, void *state);
MEMBER int ISteamController_GetConnectedControllers(struct ISteamController *iface, steam_controller_handle_t *handles);
MEMBER void ISteamController_ActivateActionSet(struct ISteamController *iface, steam_controller_handle_t handle, steam_controller_action_set_handle_t action_set_handle);
MEMBER void ISteamController_TriggerHapticPulse(struct ISteamController *iface, uint32_t index, unsigned int /* ESteamControllerPad */ target_pad, unsigned short duration_ms);
MEMBER void ISteamController_SetOverrideMode(struct ISteamController *iface, const char *mode);

#endif /* ISTEAMCONTROLLER_PRIV_H */
