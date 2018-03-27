#ifndef ISTEAMUSER017_H
#define ISTEAMUSER017_H 1

#include "steam.h"

#include "ISteamUser.h"

#define STEAMUSER_INTERFACE_VERSION_017 "SteamUser017"

struct ISteamUser017Vtbl
{
	steam_user_t (*GetHSteamUser)(struct ISteamUser *iface);
	steam_bool_t (*BLoggedOn)(struct ISteamUser *iface);
	void (*GetSteamID)(union CSteamID *ret, struct ISteamUser *iface);
	void *InitiateGameConnection;
	void (*TerminateGameConnection)(struct ISteamUser *iface, uint32_t server_ip, uint16_t server_port);
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
};

struct ISteamUser *SteamUser017(void);

#endif /* ISTEAMUSER017_H */
