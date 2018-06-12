#ifndef ISTEAMUTILS002_H
#define ISTEAMUTILS002_H 1

#include "CCallback.h"
#include "steam.h"

#include "ISteamUtils.h"

#define STEAMUTILS_INTERFACE_VERSION_002 "SteamUtils002"

struct ISteamUtils002Vtbl
{
	MEMBER uint32_t (*GetSecondsSinceAppActive)(struct ISteamUtils *iface);
	void *GetSecondsSinceComputerActive;
	MEMBER enum steam_universe (*GetConnectedUniverse)(struct ISteamUtils *iface);
	MEMBER uint32_t (*GetServerRealTime)(struct ISteamUtils *iface);
	MEMBER const char *(*GetIPCountry)(struct ISteamUtils *iface);
	void *GetImageSize;
	MEMBER steam_bool_t (*GetImageRGBA)(struct ISteamUtils *iface, int handle, uint8_t *buf, int buf_size);
	MEMBER steam_bool_t (*GetCSERIPPort)(struct ISteamUtils *iface, uint32_t *ip, uint16_t *port);
	void *GetCurrentBatteryPower;
	MEMBER steam_app_id_t (*GetAppID)(struct ISteamUtils *iface);
	MEMBER void (*SetOverlayNotificationPosition)(struct ISteamUtils *iface, enum steam_notification_position pos);
};

struct ISteamUtils *SteamUtils002(void);

#endif /* ISTEAMUTILS002_H */
