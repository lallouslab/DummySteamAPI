#ifndef ISTEAMUSER018_H
#define ISTEAMUSER018_H 1

#include "steam.h"

#include "ISteamUser.h"

#define STEAMUSER_INTERFACE_VERSION_018 "SteamUser018"

struct ISteamUser018Vtbl
{
	steam_user_t (*GetHSteamUser)(struct ISteamUser *iface);
	steam_bool_t (*BLoggedOn)(struct ISteamUser *iface);
	union CSteamID (*GetSteamID)(struct ISteamUser *iface);
	void *InitiateGameConnection;
	void *TerminateGameConnection;
	void *TrackAppUsageEvent;
	steam_bool_t (*GetUserDataFolder)(struct ISteamUser *iface, char *buf, int buf_size);
	void *StartVoiceRecording;
	void *StopVoiceRecording;
	void *GetAvailableVoice;
	void *GetVoice;
	void *DecompressVoice;
	void *GetVoiceOptimalSampleRate;
	void *GetAuthSessionTicket;
	void *BeginAuthSession;
	void *EndAuthSession;
	void *CancelAuthTicket;
	void *UserHasLicenseForApp;
	void *BIsBehindNAT;
	void *AdvertiseGame;
	steam_api_call_t (*RequestEncryptedAppTicket)(struct ISteamUser *iface, void *data, int data_size);
	void *GetEncryptedAppTicket;
	void *GetGameBadgeLevel;
	void *GetPlayerSteamLevel;
	void *RequestStoreAuthURL;
};

static inline struct ISteamUser018Vtbl *get_ISteamUser018Vtbl_from_ISteamUser(struct ISteamUser *iface) {
	return (struct ISteamUser018Vtbl *)iface->vtbl;
}

struct ISteamUser *SteamUser018(void);

#endif /* ISTEAMUSER018_H */
