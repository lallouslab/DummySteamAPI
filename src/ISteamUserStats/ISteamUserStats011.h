#ifndef ISTEAMUSERSTATS011_H
#define ISTEAMUSERSTATS011_H 1

#include "steam.h"

#include "ISteamUserStats.h"

#define STEAMUSERSTATS_INTERFACE_VERSION_011 "STEAMUSERSTATS_INTERFACE_VERSION011"

struct ISteamUserStats011Vtbl
{
	MEMBER steam_bool_t (*RequestCurrentStats)(struct ISteamUserStats *iface);
	MEMBER steam_bool_t (*GetStatI32)(struct ISteamUserStats *iface, const char *name, int32_t *data);
	MEMBER steam_bool_t (*GetStatFloat)(struct ISteamUserStats *iface, const char *name, float *data);
	MEMBER steam_bool_t (*SetStatI32)(struct ISteamUserStats *iface, const char *name, int32_t data);
	MEMBER steam_bool_t (*SetStatFloat)(struct ISteamUserStats *iface, const char *name, float data);
	MEMBER steam_bool_t (*UpdateAvgRateStat)(struct ISteamUserStats *iface, const char *name, float count_this_session, float session_length);
	MEMBER steam_bool_t (*GetAchievement)(struct ISteamUserStats *iface, const char *name, steam_bool_t *achieved);
	MEMBER steam_bool_t (*SetAchievement)(struct ISteamUserStats *iface, const char *name);
	MEMBER steam_bool_t (*ClearAchievement)(struct ISteamUserStats *iface, const char *name);
	MEMBER steam_bool_t (*GetAchievementAndUnlockTime)(struct ISteamUserStats *iface, const char *name, steam_bool_t *achieved, uint32_t *unlock_time);
	MEMBER steam_bool_t (*StoreStats)(struct ISteamUserStats *iface);
	MEMBER int (*GetAchievementIcon)(struct ISteamUserStats *iface, const char *name);
	MEMBER const char *(*GetAchievementDisplayAttribute)(struct ISteamUserStats *iface, const char *name, const char *key);
	MEMBER steam_bool_t (*IndicateAchievementProgress)(struct ISteamUserStats *iface, const char *name, uint32_t cur_progress, uint32_t max_progress);
	void *GetNumAchievements;
	void *GetAchievementName;
	MEMBER steam_api_call_t (*RequestUserStats)(struct ISteamUserStats *iface, union CSteamID steam_id_user);
	void *GetUserStatI32;
	void *GetUserStatFloat;
	void *GetUserAchievement;
	void *GetUserAchievementAndUnlockTime;
	void *ResetAllStats;
	MEMBER steam_api_call_t (*FindOrCreateLeaderboard)(struct ISteamUserStats *iface, const char *name, enum steam_user_stats_leaderboard_sort_method sort_method, enum steam_user_stats_leaderboard_display_type display_type);
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
	MEMBER steam_bool_t (*GetGlobalStatI64)(struct ISteamUserStats *iface, const char *name, int64_t *data);
	MEMBER steam_bool_t (*GetGlobalStatDouble)(struct ISteamUserStats *iface, const char *name, double *data);
	void *GetGlobalStatHistoryI64;
	void *GetGlobalStatHistorySouble;
};

struct ISteamUserStats *SteamUserStats011(void);

#endif /* ISTEAMUSERSTATS011_H */
