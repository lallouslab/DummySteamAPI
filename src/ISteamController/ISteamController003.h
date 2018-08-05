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
	MEMBER steam_controller_action_set_handle_t (*GetActionSetHandle)(struct ISteamController *iface, const char *name);
	MEMBER void (*ActivateActionSet)(struct ISteamController *iface, steam_controller_handle_t handle, steam_controller_action_set_handle_t action_set_handle);
	void *GetCurrentActionSet;
	MEMBER steam_controller_digital_action_handle_t (*GetDigitalActionHandle)(struct ISteamController *iface, const char *name);
	void *GetDigitalActionData;
	void *GetDigitalActionOrigins;
	MEMBER steam_controller_analog_action_handle_t (*GetAnalogActionHandle)(struct ISteamController *iface, const char *name);
	void *GetAnalogActionData;
	void *GetAnalogActionOrigins;
	void *StopAnalogActionMomentum;
	void *TriggerHapticPulse;
	void *TriggerRepeatedHapticPulse;
};

struct ISteamController *SteamController003(void);

#endif /* ISTEAMCONTROLLER003_H */
