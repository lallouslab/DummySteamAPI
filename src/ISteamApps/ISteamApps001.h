#ifndef ISTEAMAPPS001_H
#define ISTEAMAPPS001_H 1

#include "steam.h"

#include "ISteamApps.h"

#define STEAMAPPS_INTERFACE_VERSION_001 "STEAMAPPS_INTERFACE_VERSION001"

struct ISteamApps001Vtbl
{
	void *GetAppData;
};

static inline struct ISteamApps001Vtbl *get_ISteamApps001Vtbl_from_ISteamApps(struct ISteamApps *iface) {
	return (struct ISteamApps001Vtbl *)iface->vtbl;
}

struct ISteamApps *SteamApps001(void);

#endif /* ISTEAMAPPS001_H */
