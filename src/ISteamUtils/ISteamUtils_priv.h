#ifndef ISTEAMUTILS_PRIV_H
#define ISTEAMUTILS_PRIV_H 1

#include "callbacks.h"
#include "steam.h"

struct ISteamUtilsImpl
{
	const void *iface;
};

uint32_t ISteamUtils_GetSecondsSinceAppActive(struct ISteamUtilsImpl *This);
enum steam_universe ISteamUtils_GetConnectedUniverse(struct ISteamUtilsImpl *This);
uint32_t ISteamUtils_GetAppID(struct ISteamUtilsImpl *This);
void ISteamUtils_SetOverlayNotificationPosition(struct ISteamUtilsImpl *This, enum steam_notification_position pos);
steam_bool_t ISteamUtils_IsAPICallCompleted(struct ISteamUtilsImpl *This, steam_api_call_t api_call, steam_bool_t *failed);
steam_bool_t ISteamUtils_GetAPICallResult(struct ISteamUtilsImpl *This, steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *failed);
void ISteamUtils_SetWarningMessageHook(struct ISteamUtilsImpl *This, void *callback);
steam_bool_t ISteamUtils_IsOverlayEnabled(struct ISteamUtilsImpl *This);
const char *ISteamUtils_GetSteamUILanguage(struct ISteamUtilsImpl *This);

#endif /* ISTEAMUTILS_PRIV_H */
