#ifndef ISTEAMUGC001_H
#define ISTEAMUGC001_H 1

#include "steam.h"

#include "ISteamUGC.h"

#define STEAMUGC_INTERFACE_VERSION_001 "STEAMUGC_INTERFACE_VERSION001"

struct ISteamUGC001
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

static inline struct ISteamUGC001 *get_ISteamUGC001_from_ISteamUGC(struct ISteamUGC *iface) {
	return (struct ISteamUGC001 *)iface->iface;
}

struct ISteamUGC *SteamUGC001(void);

#endif /* ISTEAMUGC001_H */
