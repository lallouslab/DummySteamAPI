#include <stdio.h>
#include <string.h>

#include "utils.h"

#include "ISteamController.h"
#include "ISteamController_priv.h"
#include "ISteamController001.h"

steam_bool_t ISteamController_Init(struct ISteamControllerImpl *This, const char *path_to_cfg)
{
	LOG_ENTER_NOTIMPL("(This = %p, path_to_cfg = %s)", VOIDPTR(This), path_to_cfg);

	return STEAM_TRUE;
}

steam_bool_t ISteamController_Shutdown(struct ISteamControllerImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

void ISteamController_RunFrame(struct ISteamControllerImpl *This)
{
	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));
}

steam_bool_t ISteamController_GetControllerState(struct ISteamControllerImpl *This, uint32_t index, void *state)
{
	LOG_ENTER_NOTIMPL("(This = %p, index = %u, state = %p)", VOIDPTR(This), index, state);

	return STEAM_FALSE;
}

void ISteamController_TriggerHapticPulse(struct ISteamControllerImpl *This, uint32_t index, unsigned int /* ESteamControllerPad */ target_pad, unsigned short duration_ms)
{
	LOG_ENTER_NOTIMPL("(This = %p, index = %u, target_pad = %u, duration_ms = %u)", VOIDPTR(This), index, target_pad, duration_ms);
}

void ISteamController_SetOverrideMode(struct ISteamControllerImpl *This, const char *mode)
{
	LOG_ENTER_NOTIMPL("(This = %p, mode = %s)", VOIDPTR(This), mode);
}

struct ISteamControllerImpl *SteamController_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamControllerImpl *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMCONTROLLER_INTERFACE_VERSION_001, SteamController001 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = %s)", version);

	i = 0;
	while (ifaces[i].name)
	{
		if (strcmp(ifaces[i].name, version) == 0)
		{
			if (ifaces[i].iface_getter)
				return ifaces[i].iface_getter();

			break;
		}
		i++;
	}

	WARN("Unable to find ISteamController version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamControllerImpl *SteamController(void)
{
	LOG_ENTER0("()");

	return SteamController001();
}
