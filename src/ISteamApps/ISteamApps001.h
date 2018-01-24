#ifndef ISTEAMAPPS001_H
#define ISTEAMAPPS001_H 1

#include "steam.h"

#include "ISteamApps.h"

#define STEAMAPPS_INTERFACE_VERSION_001 "STEAMAPPS_INTERFACE_VERSION001"

struct ISteamApps001
{
	void *GetAppData;
};

static inline struct ISteamApps001 *get_ISteamApps001_from_ISteamApps(struct ISteamApps *iface) {
	return (struct ISteamApps001 *)iface->iface;
}

struct ISteamApps *SteamApps001(void);

#endif /* ISTEAMAPPS001_H */
