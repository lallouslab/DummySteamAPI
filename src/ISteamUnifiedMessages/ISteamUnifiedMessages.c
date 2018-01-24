#include <string.h>

#include "utils.h"

#include "ISteamUnifiedMessages.h"
#include "ISteamUnifiedMessages_priv.h"
#include "ISteamUnifiedMessages001.h"

struct ISteamUnifiedMessagesImpl *SteamUnifiedMessages_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUnifiedMessagesImpl *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_001, SteamUnifiedMessages001 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = %s)", debug_str(version));

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

EXPORT struct ISteamUnifiedMessagesImpl *SteamUnifiedMessages(void)
{
	LOG_ENTER0("()");

	return SteamUnifiedMessages001();
}
