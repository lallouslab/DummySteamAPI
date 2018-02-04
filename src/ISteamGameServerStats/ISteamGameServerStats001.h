#ifndef ISTEAMGAMESERVERSTATS001_H
#define ISTEAMGAMESERVERSTATS001_H 1

#include "steam.h"

#include "ISteamGameServerStats.h"

#define STEAMGAMESERVERSTATS_INTERFACE_VERSION_001 "SteamGameServerStats001"

struct ISteamGameServerStats001Vtbl
{
	void *RequestUserStats;
	void *GetUserStatInt;
	void *GetUserStatFloat;
	void *GetUserAchievement;
	void *SetUserStatInt;
	void *SetUserStatFloat;
	void *UpdateUserAvgRateStat;
	void *SetUserAchievement;
	void *ClearUserAchievement;
	void *StoreUserStats;
};

static inline struct ISteamGameServerStats001Vtbl *get_ISteamGameServerStats001Vtbl_from_ISteamGameServerStats(struct ISteamGameServerStats *iface) {
	return (struct ISteamGameServerStats001Vtbl *)iface->vtbl;
}

struct ISteamGameServerStats *SteamGameServerStats001(void);

#endif /* ISTEAMGAMESERVERSTATS001_H */
