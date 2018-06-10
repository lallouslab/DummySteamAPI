#ifndef ISTEAMUGC_H
#define ISTEAMUGC_H 1

#include "steam.h"

#define STEAMUGC_INTERFACE_VERSION_PREFIX "STEAMUGC_INTERFACE_VERSION"

struct ISteamUGC
{
	union
	{
		const void *ptr;
		const struct ISteamUGC001Vtbl *v001;
		const struct ISteamUGC005Vtbl *v005;
		const struct ISteamUGC007Vtbl *v007;
		const struct ISteamUGC010Vtbl *v010;
	} vtbl;
};

typedef uint64_t steam_ugc_query_handle_t;

struct ISteamUGC *SteamUGC_generic(const char *version);
void SteamUGC_set_version(const char *version);
extern struct ISteamUGC *SteamUGC(void);

#endif /* ISTEAMUGC_H */
