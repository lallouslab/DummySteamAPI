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

struct ISteamGameServerStats *SteamGameServerStats001(void);

#endif /* ISTEAMGAMESERVERSTATS001_H */
