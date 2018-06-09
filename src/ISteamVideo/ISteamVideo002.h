#ifndef ISTEAMVIDEO002_H
#define ISTEAMVIDEO002_H 1

#include "steam.h"

#include "ISteamVideo.h"

#define STEAMVIDEO_INTERFACE_VERSION_002 "STEAMVIDEO_INTERFACE_V002"

struct ISteamVideo002Vtbl
{
	void *GetVideoURL;
	void *IsBroadcasting;
	void *GetOPFSettings;
	void *GetOPFStringForApp;
};

struct ISteamVideo *SteamVideo002(void);

#endif /* ISTEAMVIDEO002_H */
