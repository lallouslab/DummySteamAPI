#ifndef ISTEAMMUSIC001_H
#define ISTEAMMUSIC001_H 1

#include "steam.h"

#include "ISteamMusic.h"

#define STEAMMUSIC_INTERFACE_VERSION_001 "STEAMMUSIC_INTERFACE_VERSION001"

struct ISteamMusic001Vtbl
{
	void *BIsEnabled;
	void *BIsPlaying;
	void *GetPlaybackStatus;
	void *Play;
	void *Pause;
	void *PlayPrevious;
	void *PlayNext;
	void *SetVolume;
	void *GetVolume;
};

struct ISteamMusic *SteamMusic001(void);

#endif /* ISTEAMMUSIC001_H */
