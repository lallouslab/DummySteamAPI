#ifndef ISTEAMHTTP001_H
#define ISTEAMHTTP001_H 1

#include "steam.h"

#include "ISteamHTTP.h"

#define STEAMHTTP_INTERFACE_VERSION_001 "STEAMHTTP_INTERFACE_VERSION001"

struct ISteamHTTP001Vtbl
{
	void *CreateHTTPRequest;
	void *SetHTTPRequestContextValue;
	void *SetHTTPRequestNetworkActivityTimeout;
	void *SetHTTPRequestHeaderValue;
	void *SetHTTPRequestGetOrPostParameter;
	void *SendHTTPRequest;
	void *DeferHTTPRequest;
	void *PrioritizeHTTPRequest;
	void *GetHTTPResponseHeaderSize;
	void *GetHTTPResponseHeaderValue;
	void *GetHTTPResponseBodySize;
	void *GetHTTPResponseBodyData;
	void *ReleaseHTTPRequest;
	void *GetHTTPDownloadProgressPct;
	void *SetHTTPRequestRawPostBody;
};

struct ISteamHTTP *SteamHTTP001(void);

#endif /* ISTEAMHTTP001_H */
