#ifndef ISTEAMMUSICREMOTE001_H
#define ISTEAMMUSICREMOTE001_H 1

#include "steam.h"

#include "ISteamMusicRemote.h"

#define STEAMMUSICREMOTE_INTERFACE_VERSION_001 "STEAMMUSICREMOTE_INTERFACE_VERSION001"

struct ISteamMusicRemote001Vtbl
{
	void *RegisterSteamMusicRemote;
	void *DeregisterSteamMusicRemote;
	void *BIsCurrentMusicRemote;
	void *BActivationSuccess;
	void *SetDisplayName;
	void *SetPNGIcon_64x64;
	void *EnablePlayPrevious;
	void *EnablePlayNext;
	void *EnableShuffled;
	void *EnableLooped;
	void *EnableQueue;
	void *EnablePlaylists;
	void *UpdatePlaybackStatus;
	void *UpdateShuffled;
	void *UpdateLooped;
	void *UpdateVolume;
	void *CurrentEntryWillChange;
	void *CurrentEntryIsAvailable;
	void *UpdateCurrentEntryText;
	void *UpdateCurrentEntryElapsedSeconds;
	void *UpdateCurrentEntryCoverArt;
	void *CurrentEntryDidChange;
	void *QueueWillChange;
	void *ResetQueueEntries;
	void *SetQueueEntry;
	void *SetCurrentQueueEntry;
	void *QueueDidChange;
	void *PlaylistWillChange;
	void *ResetPlaylistEntries;
	void *SetPlaylistEntry;
	void *SetCurrentPlaylistEntry;
	void *PlaylistDidChange;
};

static inline struct ISteamMusicRemote001Vtbl *get_ISteamMusicRemote001Vtbl_from_ISteamMusicRemote(struct ISteamMusicRemote *iface) {
	return (struct ISteamMusicRemote001Vtbl *)iface->vtbl;
}

struct ISteamMusicRemote *SteamMusicRemote001(void);

#endif /* ISTEAMMUSICREMOTE001_H */
