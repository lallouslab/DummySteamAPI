#ifndef ISTEAMUSERSTATS011_H
#define ISTEAMUSERSTATS011_H 1

#include "steam.h"

#include "ISteamUserStats.h"

#define STEAMUSERSTATS_INTERFACE_VERSION_011 "STEAMUSERSTATS_INTERFACE_VERSION011"

struct ISteamUserStats011
{
	steam_bool_t (*RequestCurrentStats)(struct ISteamUserStatsImpl *This);
	steam_bool_t (*GetStatI32)(struct ISteamUserStatsImpl *This, const char *name, int32_t *data);
	steam_bool_t (*GetStatFloat)(struct ISteamUserStatsImpl *This, const char *name, float *data);
	steam_bool_t (*SetStatI32)(struct ISteamUserStatsImpl *This, const char *name, int32_t data);
	steam_bool_t (*SetStatFloat)(struct ISteamUserStatsImpl *This, const char *name, float data);
	steam_bool_t (*UpdateAvgRateStat)(struct ISteamUserStatsImpl *This, const char *name, float count_this_session, float session_length);
	steam_bool_t (*GetAchievement)(struct ISteamUserStatsImpl *This, const char *name, steam_bool_t *achieved);
	steam_bool_t (*SetAchievement)(struct ISteamUserStatsImpl *This, const char *name);
	steam_bool_t (*ClearAchievement)(struct ISteamUserStatsImpl *This, const char *name);
	steam_bool_t (*GetAchievementAndUnlockTime)(struct ISteamUserStatsImpl *This, const char *name, steam_bool_t *achieved, uint32_t *unlock_time);
	steam_bool_t (*StoreStats)(struct ISteamUserStatsImpl *This);
	void *GetAchievementIcon;
	void *GetAchievementDisplayAttribute;
	void *IndicateAchievementProgress;
	void *GetNumAchievements;
	void *GetAchievementName;
	steam_api_call_t (*RequestUserStats)(struct ISteamUserStatsImpl *This, union CSteamID steam_id_user);
	void *GetUserStatI32;
	void *GetUserStatFloat;
	void *GetUserAchievement;
	void *GetUserAchievementAndUnlockTime;
	void *ResetAllStats;
	void *FindOrCreateLeaderboard;
	void *FindLeaderboard;
	void *GetLeaderboardName;
	void *GetLeaderboardEntryCount;
	void *GetLeaderboardSortMethod;
	void *GetLeaderboardDisplayType;
	void *DownloadLeaderboardEntries;
	void *DownloadLeaderboardEntriesForUsers;
	void *GetDownloadedLeaderboardEntry;
	void *UploadLeaderboardScore;
	void *AttachLeaderboardUGC;
	void *GetNumberOfCurrentPlayers;
	void *RequestGlobalAchievementPercentages;
	void *GetMostAchievedAchievementInfo;
	void *GetNextMostAchievedAchievementInfo;
	void *GetAchievementAchievedPercent;
	void *RequestGlobalStats;
	void *GetGlobalStatI64;
	void *GetGlobalStatDouble;
	void *GetGlobalStatHistoryI64;
	void *GetGlobalStatHistorySouble;
};

struct ISteamUserStatsImpl *SteamUserStats011(void);

#endif /* ISTEAMUSERSTATS011_H */
