#include <string.h>

#include "debug.h"

#include "ISteamVideo.h"
#include "ISteamVideo_priv.h"
#include "ISteamVideo001.h"
#include "ISteamVideo002.h"

static const char *steam_video_version = NULL;

struct ISteamVideo *SteamVideo_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamVideo *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMVIDEO_INTERFACE_VERSION_001, SteamVideo001 },
		{ STEAMVIDEO_INTERFACE_VERSION_002, SteamVideo002 },
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

	WARN("Unable to find ISteamVideo version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamVideo_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_video_version)
		steam_video_version = version;
}

EXPORT struct ISteamVideo *SteamVideo(void)
{
	static struct ISteamVideo *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_video_version)
	{
		steam_video_version = STEAMVIDEO_INTERFACE_VERSION_001;

		WARN("ISteamVideo: No version specified, defaulting to \"%s\".", debug_str(steam_video_version));
	}

	if (!cached_iface)
		cached_iface = SteamVideo_generic(steam_video_version);

	return cached_iface;
}
