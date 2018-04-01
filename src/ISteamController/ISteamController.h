#ifndef ISTEAMCONTROLLER_H
#define ISTEAMCONTROLLER_H 1

#include "steam.h"

#define STEAMCONTROLLER_INTERFACE_VERSION_PREFIX0 "STEAMCONTROLLER_INTERFACE_VERSION"
#define STEAMCONTROLLER_INTERFACE_VERSION_PREFIX1 "SteamController"

struct ISteamController
{
	union
	{
		const void *ptr;
		const struct ISteamController001Vtbl *v001;
		const struct ISteamController003Vtbl *v003;
	} vtbl;
};

typedef uint64_t steam_controller_handle_t;

struct ISteamController *SteamController_generic(const char *version);
void SteamController_set_version(const char *version);
extern struct ISteamController *SteamController(void);

#endif /* ISTEAMCONTROLLER_H */
