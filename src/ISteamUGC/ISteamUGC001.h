#ifndef ISTEAMUGC001_H
#define ISTEAMUGC001_H 1

#include "steam.h"

#include "ISteamUGC.h"

#define STEAMUGC_INTERFACE_VERSION_001 "STEAMUGC_INTERFACE_VERSION001"

struct ISteamUGC001Vtbl
{
	void *CreateQueryUserUGCRequest;
	void *CreateQueryAllUGCRequest;
	void *SendQueryUGCRequest;
	void *GetQueryUGCResult;
	void *ReleaseQueryUGCRequest;
	void *AddRequiredTag;
	void *AddExcludedTag;
	void *SetReturnLongDescription;
	void *SetReturnTotalOnly;
	void *SetCloudFileNameFilter;
	void *SetMatchAnyTag;
	void *SetSearchText;
	void *SetRankedByTrendDays;
	void *RequestUGCDetails;
};

struct ISteamUGC *SteamUGC001(void);

#endif /* ISTEAMUGC001_H */
