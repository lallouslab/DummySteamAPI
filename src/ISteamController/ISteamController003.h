#ifndef ISTEAMCONTROLLER003_H
#define ISTEAMCONTROLLER003_H 1

#include "steam.h"

#include "ISteamController.h"

#define STEAMCONTROLLER_INTERFACE_VERSION_003 "SteamController003"

struct ISteamController003Vtbl
{
	MEMBER steam_bool_t (*Init)(struct ISteamController *iface);
	MEMBER steam_bool_t (*Shutdown)(struct ISteamController *iface);
	MEMBER void (*RunFrame)(struct ISteamController *iface);
	MEMBER int (*GetConnectedControllers)(struct ISteamController *iface, steam_controller_handle_t *handles);
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

struct ISteamController *SteamController003(void);

#endif /* ISTEAMCONTROLLER003_H */
