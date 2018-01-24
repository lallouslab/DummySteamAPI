#ifndef ISTEAMUSER018_H
#define ISTEAMUSER018_H 1

#include "steam.h"

#include "ISteamUser.h"

#define STEAMUSER_INTERFACE_VERSION_018 "SteamUser018"

struct ISteamUser018
{
	steam_user_t (*GetHSteamUser)(struct ISteamUserImpl *This);
	steam_bool_t (*BLoggedOn)(struct ISteamUserImpl *This);
	union CSteamID (*GetSteamID)(struct ISteamUserImpl *This);
	void *InitiateGameConnection;
	void *TerminateGameConnection;
	void *TrackAppUsageEvent;
	steam_bool_t (*GetUserDataFolder)(struct ISteamUserImpl *This, char *buf, int buf_size);
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
	steam_api_call_t (*RequestEncryptedAppTicket)(struct ISteamUserImpl *This, void *data, int data_size);
	void *GetEncryptedAppTicket;
	void *GetGameBadgeLevel;
	void *GetPlayerSteamLevel;
	void *RequestStoreAuthURL;
};

struct ISteamUserImpl *SteamUser018(void);

#endif /* ISTEAMUSER018_H */
