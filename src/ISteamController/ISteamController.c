#include <string.h>

#include "debug.h"
#include "steam.h"

#include "ISteamController.h"
#include "ISteamController_priv.h"
#include "ISteamController001.h"
#include "ISteamController003.h"

static const char *steam_controller_version = NULL;

MEMBER steam_bool_t ISteamController_Init(struct ISteamController *iface, const char *path_to_cfg)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p, path_to_cfg = \"%s\")", VOIDPTR(This), debug_str(path_to_cfg));

	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamController_Init003(struct ISteamController *iface)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

MEMBER steam_bool_t ISteamController_Shutdown(struct ISteamController *iface)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

MEMBER void ISteamController_RunFrame(struct ISteamController *iface)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));
}

MEMBER steam_bool_t ISteamController_GetControllerState(struct ISteamController *iface, uint32_t index, void *state)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p, index = %u, state = %p)", VOIDPTR(This), index, state);

	return STEAM_FALSE;
}

MEMBER void ISteamController_TriggerHapticPulse(struct ISteamController *iface, uint32_t index, unsigned int /* ESteamControllerPad */ target_pad, unsigned short duration_ms)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p, index = %u, target_pad = %u, duration_ms = %u)", VOIDPTR(This), index, target_pad, duration_ms);
}

MEMBER void ISteamController_SetOverrideMode(struct ISteamController *iface, const char *mode)
{
	struct ISteamControllerImpl *This = impl_from_ISteamController(iface);

	LOG_ENTER_NOTIMPL("(This = %p, mode = \"%s\")", VOIDPTR(This), debug_str(mode));
}

struct ISteamController *SteamController_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamController *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMCONTROLLER_INTERFACE_VERSION_001, SteamController001 },
		{ STEAMCONTROLLER_INTERFACE_VERSION_003, SteamController003 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = \"%s\")", debug_str(version));

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

	WARN("Unable to find ISteamController version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamController_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_controller_version)
		steam_controller_version = version;
}

EXPORT struct ISteamController *SteamController(void)
{
	static struct ISteamController *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_controller_version)
	{
		steam_controller_version = STEAMCONTROLLER_INTERFACE_VERSION_003;

		WARN("ISteamController: No version specified, defaulting to \"%s\".", debug_str(steam_controller_version));
	}

	if (!cached_iface)
		cached_iface = SteamController_generic(steam_controller_version);

	return cached_iface;
}
