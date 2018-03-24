#ifndef ISTEAMCONTROLLER003_H
#define ISTEAMCONTROLLER003_H 1

#include "steam.h"

#include "ISteamController.h"

#define STEAMCONTROLLER_INTERFACE_VERSION_003 "SteamController003"

struct ISteamController003Vtbl
{
	steam_bool_t (*Init)(struct ISteamController *iface, const char *path_to_cfg);
	steam_bool_t (*Shutdown)(struct ISteamController *iface);
	void (*RunFrame)(struct ISteamController *iface);
	void *GetConnectedControllers;
	void *ShowBindingPanel;
	void *GetActionSetHandle;
	void *ActivateActionSet;
	void *GetCurrentActionSet;
	void *GetDigitalActionHandle;
	void *GetDigitalActionData;
	void *GetDigitalActionOrigins;
	void *GetAnalogActionHandle;
	void *GetAnalogActionData;
	void *GetAnalogActionOrigins;
	void *StopAnalogActionMomentum;
	void *TriggerHapticPulse;
	void *TriggerRepeatedHapticPulse;
};

static inline struct ISteamController003Vtbl *get_ISteamController003Vtbl_from_ISteamController(struct ISteamController *iface) {
	return (struct ISteamController003Vtbl *)iface->vtbl;
}

struct ISteamController *SteamController003(void);

#endif /* ISTEAMCONTROLLER003_H */
