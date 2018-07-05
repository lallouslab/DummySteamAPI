#ifndef ISTEAMCONTROLLER006_H
#define ISTEAMCONTROLLER006_H 1

#include "steam.h"

#include "ISteamController.h"

#define STEAMCONTROLLER_INTERFACE_VERSION_006 "SteamController006"

struct ISteamController006Vtbl
{
	MEMBER steam_bool_t (*Init)(struct ISteamController *iface);
	MEMBER steam_bool_t (*Shutdown)(struct ISteamController *iface);
	MEMBER void (*RunFrame)(struct ISteamController *iface);
	MEMBER int (*GetConnectedControllers)(struct ISteamController *iface, steam_controller_handle_t *handles);
	void *ShowBindingPanel;
	void *GetActionSetHandle;
	MEMBER void (*ActivateActionSet)(struct ISteamController *iface, steam_controller_handle_t handle, steam_controller_action_set_handle_t action_set_handle);
	void *GetCurrentActionSet;
	void *ActivateActionSetLayer;
	void *DeactivateActionSetLayer;
	void *DeactivateAllActionSetLayers;
	void *GetActiveActionSetLayers;
	void *GetDigitalActionHandle;
	void *GetDigitalActionData;
	void *GetDigitalActionOrigins;
	void *GetAnalogActionHandle;
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
	void *GetInputTypeForHandle;
};

struct ISteamController *SteamController006(void);

#endif /* ISTEAMCONTROLLER006_H */