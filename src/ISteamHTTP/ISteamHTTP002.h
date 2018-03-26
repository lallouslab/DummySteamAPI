#ifndef ISTEAMHTTP002_H
#define ISTEAMHTTP002_H 1

#include "steam.h"

#include "ISteamHTTP.h"

#define STEAMHTTP_INTERFACE_VERSION_002 "STEAMHTTP_INTERFACE_VERSION002"

struct ISteamHTTP002Vtbl
{
	void *CreateHTTPRequest;
	void *SetHTTPRequestContextValue;
	void *SetHTTPRequestNetworkActivityTimeout;
	void *SetHTTPRequestHeaderValue;
	void *SetHTTPRequestGetOrPostParameter;
	void *SendHTTPRequest;
	void *SendHTTPRequestAndStreamResponse;
	void *DeferHTTPRequest;
	void *PrioritizeHTTPRequest;
	void *GetHTTPResponseHeaderSize;
	void *GetHTTPResponseHeaderValue;
	void *GetHTTPResponseBodySize;
	void *GetHTTPResponseBodyData;
	void *GetHTTPStreamingResponseBodyData;
	void *ReleaseHTTPRequest;
	void *GetHTTPDownloadProgressPct;
	void *SetHTTPRequestRawPostBody;
	void *CreateCookieContainer;
	void *ReleaseCookieContainer;
	void *SetCookie;
	void *SetHTTPRequestCookieContainer;
	void *SetHTTPRequestUserAgentInfo;
	void *SetHTTPRequestRequiresVerifiedCertificate;
	void *SetHTTPRequestAbsoluteTimeoutMS;
	void *GetHTTPRequestWasTimedOut;
};

struct ISteamHTTP *SteamHTTP002(void);

#endif /* ISTEAMHTTP002_H */
