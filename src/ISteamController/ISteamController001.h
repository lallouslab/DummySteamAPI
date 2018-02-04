#ifndef ISTEAMCONTROLLER001_H
#define ISTEAMCONTROLLER001_H 1

#include "steam.h"

#include "ISteamController.h"

#define STEAMCONTROLLER_INTERFACE_VERSION_001 "STEAMCONTROLLER_INTERFACE_VERSION"

struct ISteamController001Vtbl
{
	steam_bool_t (*Init)(struct ISteamController *iface, const char *path_to_cfg);
	steam_bool_t (*Shutdown)(struct ISteamController *iface);
	void (*RunFrame)(struct ISteamController *iface);
	steam_bool_t (*GetControllerState)(struct ISteamController *iface, uint32_t index, void *state);
	void (*TriggerHapticPulse)(struct ISteamController *iface, uint32_t index, unsigned int /* ESteamControllerPad */ target_pad, unsigned short duration_ms);
	void (*SetOverrideMode)(struct ISteamController *iface, const char *mode);
};

static inline struct ISteamController001Vtbl *get_ISteamController001Vtbl_from_ISteamController(struct ISteamController *iface) {
	return (struct ISteamController001Vtbl *)iface->vtbl;
}

struct ISteamController *SteamController001(void);

#endif /* ISTEAMCONTROLLER001_H */
