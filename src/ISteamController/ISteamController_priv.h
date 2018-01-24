#ifndef ISTEAMCONTROLLER_PRIV_H
#define ISTEAMCONTROLLER_PRIV_H 1

#include "steam.h"

struct ISteamControllerImpl
{
	const void *iface;
};

steam_bool_t ISteamController_Init(struct ISteamControllerImpl *This, const char *path_to_cfg);
steam_bool_t ISteamController_Shutdown(struct ISteamControllerImpl *This);
void ISteamController_RunFrame(struct ISteamControllerImpl *This);
steam_bool_t ISteamController_GetControllerState(struct ISteamControllerImpl *This, uint32_t index, void *state);
void ISteamController_TriggerHapticPulse(struct ISteamControllerImpl *This, uint32_t index, unsigned int /* ESteamControllerPad */ target_pad, unsigned short duration_ms);
void ISteamController_SetOverrideMode(struct ISteamControllerImpl *This, const char *mode);

#endif /* ISTEAMCONTROLLER_PRIV_H */
