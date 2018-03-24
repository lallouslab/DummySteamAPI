#include <string.h>

#include "debug.h"
#include "utils.h"

#include "ISteamMusic.h"
#include "ISteamMusic_priv.h"
#include "ISteamMusic001.h"

static const char *steam_music_version = NULL;

struct ISteamMusic *SteamMusic_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamMusic *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMMUSIC_INTERFACE_VERSION_001, SteamMusic001 },
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

	WARN("Unable to find ISteamMusic version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamMusic_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_music_version)
		steam_music_version = version;
}

EXPORT struct ISteamMusic *SteamMusic(void)
{
	static struct ISteamMusic *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_music_version)
	{
		steam_music_version = STEAMMUSIC_INTERFACE_VERSION_001;

		WARN("ISteamMusic: No version specified, defaulting to \"%s\".", debug_str(steam_music_version));
	}

	if (!cached_iface)
		cached_iface = SteamMusic_generic(steam_music_version);

	return cached_iface;
}
