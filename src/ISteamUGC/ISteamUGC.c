#include <string.h>

#include "utils.h"

#include "ISteamUGC.h"
#include "ISteamUGC_priv.h"
#include "ISteamUGC001.h"

struct ISteamUGC *SteamUGC_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUGC *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUGC_INTERFACE_VERSION_001, SteamUGC001 },
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

	WARN("Unable to find ISteamUGC version \"%s\".", version);

	return INVAL_PTR;
}

EXPORT struct ISteamUGC *SteamUGC(void)
{
	LOG_ENTER0("()");

	return SteamUGC001();
}
