#ifndef ISTEAMUTILS001_H
#define ISTEAMUTILS001_H 1

#include "steam.h"

#include "ISteamUtils.h"

#define STEAMUTILS_INTERFACE_VERSION_001 "SteamUtils001"

struct ISteamUtils001Vtbl
{
	MEMBER uint32_t (*GetSecondsSinceAppActive)(struct ISteamUtils *iface);
	void *GetSecondsSinceComputerActive;
	MEMBER enum steam_universe (*GetConnectedUniverse)(struct ISteamUtils *iface);
	MEMBER uint32_t (*GetServerRealTime)(struct ISteamUtils *iface);
	MEMBER const char *(*GetIPCountry)(struct ISteamUtils *iface);
	MEMBER steam_bool_t (*GetImageSize)(struct ISteamUtils *iface, int handle, uint32_t *w, uint32_t *h);
	MEMBER steam_bool_t (*GetImageRGBA)(struct ISteamUtils *iface, int handle, uint8_t *buf, int buf_size);
};

struct ISteamUtils *SteamUtils001(void);

#endif /* ISTEAMUTILS001_H */
