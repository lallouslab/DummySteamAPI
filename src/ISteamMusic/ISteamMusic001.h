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

static inline struct ISteamMusic001Vtbl *get_ISteamMusic001Vtbl_from_ISteamMusic(struct ISteamMusic *iface) {
	return (struct ISteamMusic001Vtbl *)iface->vtbl;
}

struct ISteamMusic *SteamMusic001(void);

#endif /* ISTEAMMUSIC001_H */
