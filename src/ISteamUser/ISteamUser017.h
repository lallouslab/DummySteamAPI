#ifndef ISTEAMUSER017_H
#define ISTEAMUSER017_H 1

#include "steam.h"

#include "ISteamUser.h"

#define STEAMUSER_INTERFACE_VERSION_017 "SteamUser017"

struct ISteamUser017Vtbl
{
	MEMBER steam_user_t (*GetHSteamUser)(struct ISteamUser *iface);
	MEMBER steam_bool_t (*BLoggedOn)(struct ISteamUser *iface);
	DSA_PFN_MEMBER_RETURN_STRUCT0(union CSteamID, ret, GetSteamID, struct ISteamUser *iface);
	MEMBER int (*InitiateGameConnection)(struct ISteamUser *iface, void *auth_blob, int auth_blob_size, union CSteamID steam_id_game_server, uint32_t server_ip, uint16_t server_port, steam_bool_t secure);
	MEMBER void (*TerminateGameConnection)(struct ISteamUser *iface, uint32_t server_ip, uint16_t server_port);
	void *TrackAppUsageEvent;
	MEMBER steam_bool_t (*GetUserDataFolder)(struct ISteamUser *iface, char *buf, int buf_size);
	void *StartVoiceRecording;
	void *StopVoiceRecording;
	void *GetAvailableVoice;
	void *GetVoice;
	void *DecompressVoice;
	void *GetVoiceOptimalSampleRate;
	MEMBER steam_auth_ticket_handle_t (*GetAuthSessionTicket)(struct ISteamUser *iface, void *buf, int buf_size, uint32_t *ticket_len);
	void *BeginAuthSession;
	void *EndAuthSession;
	MEMBER void (*CancelAuthTicket)(struct ISteamUser *iface, steam_auth_ticket_handle_t ticket_handle);
	void *UserHasLicenseForApp;
	void *BIsBehindNAT;
	MEMBER void (*AdvertiseGame)(struct ISteamUser *iface, union CSteamID steam_id_game_server, uint32_t server_ip, uint16_t server_port);
	MEMBER steam_api_call_t (*RequestEncryptedAppTicket)(struct ISteamUser *iface, void *data, int data_size);
	void *GetEncryptedAppTicket;
	void *GetGameBadgeLevel;
	void *GetPlayerSteamLevel;
};

#define ISteamUser017_GetSteamID(iface, ret) DSA_CALL_MEMBER_RETURN_STRUCT0(iface->vtbl.v017->GetSteamID, ret, iface)

struct ISteamUser *SteamUser017(void);

#endif /* ISTEAMUSER017_H */
