#include <string.h>

#include "utils.h"

#include "ISteamHTTP.h"
#include "ISteamHTTP_priv.h"
#include "ISteamHTTP001.h"
#include "ISteamHTTP002.h"

static const char *steam_http_version = NULL;

struct ISteamHTTP *SteamHTTP_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamHTTP *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMHTTP_INTERFACE_VERSION_001, SteamHTTP001 },
		{ STEAMHTTP_INTERFACE_VERSION_002, SteamHTTP002 },
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

	WARN("Unable to find ISteamHTTP version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamHTTP_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	steam_http_version = version;
}

EXPORT struct ISteamHTTP *SteamHTTP(void)
{
	LOG_ENTER0("()");

	if (!steam_http_version)
	{
		steam_http_version = STEAMHTTP_INTERFACE_VERSION_002;

		WARN("ISteamHTTP: No version specified, defaulting to \"%s\".", debug_str(steam_http_version));
	}

	return SteamHTTP_generic(steam_http_version);
}
