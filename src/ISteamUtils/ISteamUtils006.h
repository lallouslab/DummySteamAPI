#ifndef ISTEAMUTILS006_H
#define ISTEAMUTILS006_H 1

#include "CCallback.h"
#include "steam.h"

#include "ISteamUtils.h"

#define STEAMUTILS_INTERFACE_VERSION_006 "SteamUtils006"

struct ISteamUtils006Vtbl
{
	MEMBER uint32_t (*GetSecondsSinceAppActive)(struct ISteamUtils *iface);
	void *GetSecondsSinceComputerActive;
	MEMBER enum steam_universe (*GetConnectedUniverse)(struct ISteamUtils *iface);
	MEMBER uint32_t (*GetServerRealTime)(struct ISteamUtils *iface);
	MEMBER const char *(*GetIPCountry)(struct ISteamUtils *iface);
	MEMBER steam_bool_t (*GetImageSize)(struct ISteamUtils *iface, int handle, uint32_t *w, uint32_t *h);
	MEMBER steam_bool_t (*GetImageRGBA)(struct ISteamUtils *iface, int handle, uint8_t *buf, int buf_size);
	MEMBER steam_bool_t (*GetCSERIPPort)(struct ISteamUtils *iface, uint32_t *ip, uint16_t *port);
	void *GetCurrentBatteryPower;
	MEMBER steam_app_id_t (*GetAppID)(struct ISteamUtils *iface);
	MEMBER void (*SetOverlayNotificationPosition)(struct ISteamUtils *iface, enum steam_notification_position pos);
	MEMBER steam_bool_t (*IsAPICallCompleted)(struct ISteamUtils *iface, steam_api_call_t api_call, steam_bool_t *failed);
	void *GetAPICallFailureReason;
	MEMBER steam_bool_t (*GetAPICallResult)(struct ISteamUtils *iface, steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *failed);
	void *RunFrame;
	void *GetIPCCallCount;
	MEMBER void (*SetWarningMessageHook)(struct ISteamUtils *iface, void * /* SteamAPIWarningMessageHook_t */ callback);
	MEMBER steam_bool_t (*IsOverlayEnabled)(struct ISteamUtils *iface);
	void *BOverlayNeedsPresent;
	void *CheckFileSignature;
	void *ShowGamepadTextInput;
	void *GetEnteredGamepadTextLength;
	void *GetEnteredGamepadTextInput;
	MEMBER const char *(*GetSteamUILanguage)(struct ISteamUtils *iface);
	void *IsSteamRunningInVR;
};

struct ISteamUtils *SteamUtils006(void);

#endif /* ISTEAMUTILS006_H */
