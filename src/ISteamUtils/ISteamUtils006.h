#ifndef ISTEAMUTILS006_H
#define ISTEAMUTILS006_H 1

#include "callbacks.h"
#include "steam.h"

#include "ISteamUtils.h"

#define STEAMUTILS_INTERFACE_VERSION_006 "SteamUtils006"

struct ISteamUtils006
{
	uint32_t (*GetSecondsSinceAppActive)(struct ISteamUtilsImpl *This);
	void *GetSecondsSinceComputerActive;
	enum steam_universe (*GetConnectedUniverse)(struct ISteamUtilsImpl *This);
	void *GetServerRealTime;
	void *GetIPCountry;
	void *GetImageSize;
	void *GetImageRGBA;
	void *GetCSERIPPort;
	void *GetCurrentBatteryPower;
	uint32_t (*GetAppID)(struct ISteamUtilsImpl *This);
	void (*SetOverlayNotificationPosition)(struct ISteamUtilsImpl *This, enum steam_notification_position pos);
	steam_bool_t (*IsAPICallCompleted)(struct ISteamUtilsImpl *This, steam_api_call_t api_call, steam_bool_t *failed);
	void *GetAPICallFailureReason;
	steam_bool_t (*GetAPICallResult)(struct ISteamUtilsImpl *This, steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *failed);
	void *RunFrame;
	void *GetIPCCallCount;
	void (*SetWarningMessageHook)(struct ISteamUtilsImpl *This, void * /* SteamAPIWarningMessageHook_t */ callback);
	steam_bool_t (*IsOverlayEnabled)(struct ISteamUtilsImpl *This);
	void *BOverlayNeedsPresent;
	void *CheckFileSignature;
	void *ShowGamepadTextInput;
	void *GetEnteredGamepadTextLength;
	void *GetEnteredGamepadTextInput;
	const char *(*GetSteamUILanguage)(struct ISteamUtilsImpl *This);
	void *IsSteamRunningInVR;
};

struct ISteamUtilsImpl *SteamUtils006(void);

#endif /* ISTEAMUTILS006_H */
