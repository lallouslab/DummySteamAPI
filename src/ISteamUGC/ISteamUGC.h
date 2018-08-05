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
		const struct ISteamUGC009Vtbl *v009;
		const struct ISteamUGC010Vtbl *v010;
	} vtbl;
};

typedef uint64_t steam_ugc_query_handle_t;

#define STEAM_UGC_QUERY_HANDLE_INVAL UINT64_C(0xFFFFFFFFFFFFFFFF)

PACKED_STRUCT steam_callback_data_ugc_query_completed
{
	steam_ugc_query_handle_t handle;
	enum steam_result result;
	uint32_t returned_count;
	uint32_t total_count;
	steam_bool_t is_data_cached;
};

struct ISteamUGC *SteamUGC_generic(const char *version);
void SteamUGC_set_version(const char *version);
extern struct ISteamUGC *SteamUGC(void);

#endif /* ISTEAMUGC_H */
