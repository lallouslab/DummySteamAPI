#ifndef ISTEAMUGC001_H
#define ISTEAMUGC001_H 1

#include "steam.h"

#include "ISteamUGC.h"

#define STEAMUGC_INTERFACE_VERSION_001 "STEAMUGC_INTERFACE_VERSION001"

struct ISteamUGC001Vtbl
{
	void *CreateQueryUserUGCRequest;
	void *CreateQueryAllUGCRequest;
	MEMBER steam_api_call_t (*SendQueryUGCRequest)(struct ISteamUGC *iface, steam_ugc_query_handle_t handle);
	void *GetQueryUGCResult;
	MEMBER steam_bool_t (*ReleaseQueryUGCRequest)(struct ISteamUGC *iface, steam_ugc_query_handle_t handle);
	void *AddRequiredTag;
	void *AddExcludedTag;
	MEMBER steam_bool_t (*SetReturnLongDescription)(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_long_desc);
	MEMBER steam_bool_t (*SetReturnTotalOnly)(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_total_only);
	void *SetCloudFileNameFilter;
	void *SetMatchAnyTag;
	void *SetSearchText;
	void *SetRankedByTrendDays;
	void *RequestUGCDetails;
};

struct ISteamUGC *SteamUGC001(void);

#endif /* ISTEAMUGC001_H */
