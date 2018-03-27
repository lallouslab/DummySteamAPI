#ifndef ISTEAMCONTROLLER001_H
#define ISTEAMCONTROLLER001_H 1

#include "steam.h"

#include "ISteamController.h"

#define STEAMCONTROLLER_INTERFACE_VERSION_001 "STEAMCONTROLLER_INTERFACE_VERSION"

struct ISteamController001Vtbl
{
	MEMBER steam_bool_t (*Init)(struct ISteamController *iface, const char *path_to_cfg);
	MEMBER steam_bool_t (*Shutdown)(struct ISteamController *iface);
	MEMBER void (*RunFrame)(struct ISteamController *iface);
	MEMBER steam_bool_t (*GetControllerState)(struct ISteamController *iface, uint32_t index, void *state);
	MEMBER void (*TriggerHapticPulse)(struct ISteamController *iface, uint32_t index, unsigned int /* ESteamControllerPad */ target_pad, unsigned short duration_ms);
	MEMBER void (*SetOverrideMode)(struct ISteamController *iface, const char *mode);
};

struct ISteamController *SteamController001(void);

#endif /* ISTEAMCONTROLLER001_H */
