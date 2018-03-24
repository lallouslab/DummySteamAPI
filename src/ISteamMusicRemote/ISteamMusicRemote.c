#include <string.h>

#include "debug.h"
#include "utils.h"

#include "ISteamMusicRemote.h"
#include "ISteamMusicRemote_priv.h"
#include "ISteamMusicRemote001.h"

static const char *steam_music_remote_version = NULL;

struct ISteamMusicRemote *SteamMusicRemote_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamMusicRemote *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMMUSICREMOTE_INTERFACE_VERSION_001, SteamMusicRemote001 },
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

	WARN("Unable to find ISteamMusicRemote version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamMusicRemote_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_music_remote_version)
		steam_music_remote_version = version;
}

EXPORT struct ISteamMusicRemote *SteamMusicRemote(void)
{
	static struct ISteamMusicRemote *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_music_remote_version)
	{
		steam_music_remote_version = STEAMMUSICREMOTE_INTERFACE_VERSION_001;

		WARN("ISteamMusicRemote: No version specified, defaulting to \"%s\".", debug_str(steam_music_remote_version));
	}

	if (!cached_iface)
		cached_iface = SteamMusicRemote_generic(steam_music_remote_version);

	return cached_iface;
}
