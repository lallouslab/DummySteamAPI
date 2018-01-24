#ifndef ISTEAMGAMESERVERSTATS001_H
#define ISTEAMGAMESERVERSTATS001_H 1

#include "steam.h"

#include "ISteamGameServerStats.h"

#define STEAMGAMESERVERSTATS_INTERFACE_VERSION_001 "SteamGameServerStats001"

struct ISteamGameServerStats001
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

struct ISteamGameServerStatsImpl *SteamGameServerStats001(void);

#endif /* ISTEAMGAMESERVERSTATS001_H */
