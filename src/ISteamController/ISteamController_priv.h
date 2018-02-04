#ifndef ISTEAMCONTROLLER_PRIV_H
#define ISTEAMCONTROLLER_PRIV_H 1

#include "steam.h"
#include "utils.h"

#include "ISteamController.h"

struct ISteamControllerImpl
{
	struct ISteamController base;
};

static inline struct ISteamControllerImpl *impl_from_ISteamController(struct ISteamController *iface) {
	return CONTAINER_OF(iface, struct ISteamControllerImpl, base);
}

steam_bool_t ISteamController_Init(struct ISteamController *iface, const char *path_to_cfg);
steam_bool_t ISteamController_Shutdown(struct ISteamController *iface);
void ISteamController_RunFrame(struct ISteamController *iface);
steam_bool_t ISteamController_GetControllerState(struct ISteamController *iface, uint32_t index, void *state);
void ISteamController_TriggerHapticPulse(struct ISteamController *iface, uint32_t index, unsigned int /* ESteamControllerPad */ target_pad, unsigned short duration_ms);
void ISteamController_SetOverrideMode(struct ISteamController *iface, const char *mode);

#endif /* ISTEAMCONTROLLER_PRIV_H */
