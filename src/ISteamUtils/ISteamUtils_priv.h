#ifndef ISTEAMUTILS_PRIV_H
#define ISTEAMUTILS_PRIV_H 1

#include "CCallback.h"
#include "steam.h"

#include "ISteamUtils.h"

struct ISteamUtilsImpl
{
	struct ISteamUtils base;
};

static inline struct ISteamUtilsImpl *impl_from_ISteamUtils(struct ISteamUtils *iface) {
	return CONTAINER_OF(iface, struct ISteamUtilsImpl, base);
}

uint32_t ISteamUtils_GetSecondsSinceAppActive(struct ISteamUtils *iface);
enum steam_universe ISteamUtils_GetConnectedUniverse(struct ISteamUtils *iface);
steam_bool_t ISteamUtils_GetCSERIPPort(struct ISteamUtils *iface, uint32_t *ip, uint16_t *port);
uint32_t ISteamUtils_GetAppID(struct ISteamUtils *iface);
void ISteamUtils_SetOverlayNotificationPosition(struct ISteamUtils *iface, enum steam_notification_position pos);
steam_bool_t ISteamUtils_IsAPICallCompleted(struct ISteamUtils *iface, steam_api_call_t api_call, steam_bool_t *failed);
steam_bool_t ISteamUtils_GetAPICallResult(struct ISteamUtils *iface, steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *failed);
void ISteamUtils_SetWarningMessageHook(struct ISteamUtils *iface, void *callback);
steam_bool_t ISteamUtils_IsOverlayEnabled(struct ISteamUtils *iface);
const char *ISteamUtils_GetSteamUILanguage(struct ISteamUtils *iface);

#endif /* ISTEAMUTILS_PRIV_H */
