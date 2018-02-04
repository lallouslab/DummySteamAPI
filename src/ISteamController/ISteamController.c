#include <string.h>

#include "utils.h"

#include "ISteamController.h"
#include "ISteamController_priv.h"
#include "ISteamController001.h"

steam_bool_t ISteamController_Init(struct ISteamController *iface, const char *path_to_cfg)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p, path_to_cfg = %s)", VOIDPTR(This), path_to_cfg);

	return STEAM_TRUE;
}

steam_bool_t ISteamController_Shutdown(struct ISteamController *iface)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

void ISteamController_RunFrame(struct ISteamController *iface)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));
}

steam_bool_t ISteamController_GetControllerState(struct ISteamController *iface, uint32_t index, void *state)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p, index = %u, state = %p)", VOIDPTR(This), index, state);

	return STEAM_FALSE;
}

void ISteamController_TriggerHapticPulse(struct ISteamController *iface, uint32_t index, unsigned int /* ESteamControllerPad */ target_pad, unsigned short duration_ms)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p, index = %u, target_pad = %u, duration_ms = %u)", VOIDPTR(This), index, target_pad, duration_ms);
}

void ISteamController_SetOverrideMode(struct ISteamController *iface, const char *mode)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p, mode = %s)", VOIDPTR(This), mode);
}

struct ISteamController *SteamController_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamController *(*iface_getter)(void);
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

EXPORT struct ISteamController *SteamController(void)
{
	LOG_ENTER0("()");

	return SteamController001();
}
