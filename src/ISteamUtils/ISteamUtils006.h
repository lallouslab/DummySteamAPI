#ifndef ISTEAMUTILS006_H
#define ISTEAMUTILS006_H 1

#include "callbacks.h"
#include "steam.h"

#include "ISteamUtils.h"

#define STEAMUTILS_INTERFACE_VERSION_006 "SteamUtils006"

struct ISteamUtils006Vtbl
{
	uint32_t (*GetSecondsSinceAppActive)(struct ISteamUtils *iface);
	void *GetSecondsSinceComputerActive;
	enum steam_universe (*GetConnectedUniverse)(struct ISteamUtils *iface);
	void *GetServerRealTime;
	void *GetIPCountry;
	void *GetImageSize;
	void *GetImageRGBA;
	void *GetCSERIPPort;
	void *GetCurrentBatteryPower;
	uint32_t (*GetAppID)(struct ISteamUtils *iface);
	void (*SetOverlayNotificationPosition)(struct ISteamUtils *iface, enum steam_notification_position pos);
	steam_bool_t (*IsAPICallCompleted)(struct ISteamUtils *iface, steam_api_call_t api_call, steam_bool_t *failed);
	void *GetAPICallFailureReason;
	steam_bool_t (*GetAPICallResult)(struct ISteamUtils *iface, steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *failed);
	void *RunFrame;
	void *GetIPCCallCount;
	void (*SetWarningMessageHook)(struct ISteamUtils *iface, void * /* SteamAPIWarningMessageHook_t */ callback);
	steam_bool_t (*IsOverlayEnabled)(struct ISteamUtils *iface);
	void *BOverlayNeedsPresent;
	void *CheckFileSignature;
	void *ShowGamepadTextInput;
	void *GetEnteredGamepadTextLength;
	void *GetEnteredGamepadTextInput;
	const char *(*GetSteamUILanguage)(struct ISteamUtils *iface);
	void *IsSteamRunningInVR;
};

struct ISteamUtils *SteamUtils006(void);

#endif /* ISTEAMUTILS006_H */
