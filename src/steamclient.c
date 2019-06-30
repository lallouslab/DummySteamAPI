#include "debug.h"
#include "steam.h"
#include "steam_api.h"
#include "steamclient.h"

EXPORT void *CreateInterface(const char *version, enum steam_result *result)
{
	void *iface;

	LOG_ENTER("(version = \"%s\", result = %p)", debug_str(version), VOIDPTR(result));

	iface = SteamInternal_CreateInterface(version);

	if (result)
		*result = iface ? STEAM_RESULT_OK : STEAM_RESULT_FAIL;

	return iface;
}

EXPORT void Steam_ReleaseThreadLocalMemory(steam_bool_t thread_exit)
{
	LOG_ENTER("(thread_exit = %u)", thread_exit);
}
