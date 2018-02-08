#include <string.h>

#include "utils.h"

#include "ISteamUnifiedMessages.h"
#include "ISteamUnifiedMessages_priv.h"
#include "ISteamUnifiedMessages001.h"

static const char *steam_unified_messages_version = NULL;

struct ISteamUnifiedMessages *SteamUnifiedMessages_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUnifiedMessages *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_001, SteamUnifiedMessages001 },
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

	WARN("Unable to find ISteamUnifiedMessages version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamUnifiedMessages_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_unified_messages_version)
		steam_unified_messages_version = version;
}

EXPORT struct ISteamUnifiedMessages *SteamUnifiedMessages(void)
{
	static struct ISteamUnifiedMessages *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_unified_messages_version)
	{
		steam_unified_messages_version = STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_001;

		WARN("ISteamUnifiedMessages: No version specified, defaulting to \"%s\".", debug_str(steam_unified_messages_version));
	}

	if (!cached_iface)
		cached_iface = SteamUnifiedMessages_generic(steam_unified_messages_version);

	return cached_iface;
}
