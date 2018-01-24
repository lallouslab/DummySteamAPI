#ifndef ISTEAMCONTROLLER001_H
#define ISTEAMCONTROLLER001_H 1

#include "steam.h"

#include "ISteamController.h"

#define STEAMCONTROLLER_INTERFACE_VERSION_001 "STEAMCONTROLLER_INTERFACE_VERSION"

struct ISteamController001
{
	steam_bool_t (*Init)(struct ISteamControllerImpl *This, const char *path_to_cfg);
	steam_bool_t (*Shutdown)(struct ISteamControllerImpl *This);
	void (*RunFrame)(struct ISteamControllerImpl *This);
	steam_bool_t (*GetControllerState)(struct ISteamControllerImpl *This, uint32_t index, void *state);
	void (*TriggerHapticPulse)(struct ISteamControllerImpl *This, uint32_t index, unsigned int /* ESteamControllerPad */ target_pad, unsigned short duration_ms);
	void (*SetOverrideMode)(struct ISteamControllerImpl *This, const char *mode);
};

struct ISteamControllerImpl *SteamController001(void);

#endif /* ISTEAMCONTROLLER001_H */
