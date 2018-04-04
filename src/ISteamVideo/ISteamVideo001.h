#ifndef ISTEAMVIDEO001_H
#define ISTEAMVIDEO001_H 1

#include "steam.h"

#include "ISteamVideo.h"

#define STEAMVIDEO_INTERFACE_VERSION_001 "STEAMVIDEO_INTERFACE_V001"

struct ISteamVideo001Vtbl
{
	void *GetVideoURL;
	void *IsBroadcasting;
};

struct ISteamVideo *SteamVideo001(void);

#endif /* ISTEAMVIDEO001_H */
