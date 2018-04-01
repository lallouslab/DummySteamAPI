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

MEMBER uint32_t ISteamUtils_GetSecondsSinceAppActive(struct ISteamUtils *iface);
MEMBER enum steam_universe ISteamUtils_GetConnectedUniverse(struct ISteamUtils *iface);
MEMBER uint32_t ISteamUtils_GetServerRealTime(struct ISteamUtils *iface);
MEMBER const char *ISteamUtils_GetIPCountry(struct ISteamUtils *iface);
MEMBER steam_bool_t ISteamUtils_GetCSERIPPort(struct ISteamUtils *iface, uint32_t *ip, uint16_t *port);
MEMBER uint32_t ISteamUtils_GetAppID(struct ISteamUtils *iface);
MEMBER void ISteamUtils_SetOverlayNotificationPosition(struct ISteamUtils *iface, enum steam_notification_position pos);
MEMBER steam_bool_t ISteamUtils_IsAPICallCompleted(struct ISteamUtils *iface, steam_api_call_t api_call, steam_bool_t *failed);
MEMBER steam_bool_t ISteamUtils_GetAPICallResult(struct ISteamUtils *iface, steam_api_call_t api_call, void *data, int data_size, enum steam_callback_type type_expected, steam_bool_t *failed);
MEMBER void ISteamUtils_SetWarningMessageHook(struct ISteamUtils *iface, void *callback);
MEMBER steam_bool_t ISteamUtils_IsOverlayEnabled(struct ISteamUtils *iface);
MEMBER const char *ISteamUtils_GetSteamUILanguage(struct ISteamUtils *iface);

#endif /* ISTEAMUTILS_PRIV_H */
