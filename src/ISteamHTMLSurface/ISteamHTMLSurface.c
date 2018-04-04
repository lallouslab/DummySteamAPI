#include <string.h>

#include "debug.h"

#include "ISteamHTMLSurface.h"
#include "ISteamHTMLSurface_priv.h"
#include "ISteamHTMLSurface002.h"

static const char *steam_html_surface_version = NULL;

struct ISteamHTMLSurface *SteamHTMLSurface_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamHTMLSurface *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMHTMLSURFACE_INTERFACE_VERSION_002, SteamHTMLSurface002 },
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

	WARN("Unable to find ISteamHTMLSurface version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamHTMLSurface_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_html_surface_version)
		steam_html_surface_version = version;
}

EXPORT struct ISteamHTMLSurface *SteamHTMLSurface(void)
{
	static struct ISteamHTMLSurface *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_html_surface_version)
	{
		steam_html_surface_version = STEAMHTMLSURFACE_INTERFACE_VERSION_002;

		WARN("ISteamHTMLSurface: No version specified, defaulting to \"%s\".", debug_str(steam_html_surface_version));
	}

	if (!cached_iface)
		cached_iface = SteamHTMLSurface_generic(steam_html_surface_version);

	return cached_iface;
}
