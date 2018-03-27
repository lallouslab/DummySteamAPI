#ifndef ISTEAMUSER018_H
#define ISTEAMUSER018_H 1

#include "steam.h"

#include "ISteamUser.h"

#define STEAMUSER_INTERFACE_VERSION_018 "SteamUser018"

struct ISteamUser018Vtbl
{
	MEMBER steam_user_t (*GetHSteamUser)(struct ISteamUser *iface);
	MEMBER steam_bool_t (*BLoggedOn)(struct ISteamUser *iface);
	MEMBER union CSteamID (*GetSteamID)(struct ISteamUser *iface);
	void *InitiateGameConnection;
	MEMBER void (*TerminateGameConnection)(struct ISteamUser *iface, uint32_t server_ip, uint16_t server_port);
	void *TrackAppUsageEvent;
	MEMBER steam_bool_t (*GetUserDataFolder)(struct ISteamUser *iface, char *buf, int buf_size);
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
	MEMBER steam_api_call_t (*RequestEncryptedAppTicket)(struct ISteamUser *iface, void *data, int data_size);
	void *GetEncryptedAppTicket;
	void *GetGameBadgeLevel;
	void *GetPlayerSteamLevel;
	void *RequestStoreAuthURL;
};

struct ISteamUser *SteamUser018(void);

#endif /* ISTEAMUSER018_H */
