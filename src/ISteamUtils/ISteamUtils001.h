#ifndef ISTEAMUTILS001_H
#define ISTEAMUTILS001_H 1

#include "steam.h"

#include "ISteamUtils.h"

#define STEAMUTILS_INTERFACE_VERSION_001 "SteamUtils001"

struct ISteamUtils001Vtbl
{
	uint32_t (*GetSecondsSinceAppActive)(struct ISteamUtils *iface);
	void *GetSecondsSinceComputerActive;
	enum steam_universe (*GetConnectedUniverse)(struct ISteamUtils *iface);
	void *GetServerRealTime;
	void *GetIPCountry;
	void *GetImageSize;
	void *GetImageRGBA;
};

static inline struct ISteamUtils001Vtbl *get_ISteamUtils001Vtbl_from_ISteamUtils(struct ISteamUtils *iface) {
	return (struct ISteamUtils001Vtbl *)iface->vtbl;
}

struct ISteamUtils *SteamUtils001(void);

#endif /* ISTEAMUTILS001_H */