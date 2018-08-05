#ifndef ISTEAMCONTROLLER005_H
#define ISTEAMCONTROLLER005_H 1

#include "steam.h"

#include "ISteamController.h"

#define STEAMCONTROLLER_INTERFACE_VERSION_005 "SteamController005"

struct ISteamController005Vtbl
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
	void *TriggerVibration;
	void *SetLEDColor;
	void *GetGamepadIndexForController;
	void *GetControllerForGamepadIndex;
	void *GetMotionData;
	void *ShowDigitalActionOrigins;
	void *ShowAnalogActionOrigins;
	void *GetStringForActionOrigin;
	void *GetGlyphForActionOrigin;
};

struct ISteamController *SteamController005(void);

#endif /* ISTEAMCONTROLLER005_H */
