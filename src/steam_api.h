#ifndef STEAM_API_H
#define STEAM_API_H 1

#include "CCallback.h"
#include "steam.h"

struct CSteamAPIContext
{
	struct ISteamClient *steam_client;
	struct ISteamUser *steam_user;
	struct ISteamFriends *steam_friends;
	struct ISteamUtils *steam_utils;
	struct ISteamMatchmaking *steam_matchmaking;
	struct ISteamUserStats *steam_user_stats;
	struct ISteamApps *steam_apps;
	struct ISteamMatchmakingServers *steam_matchmaking_servers;
	struct ISteamNetworking *steam_networking;
	struct ISteamRemoteStorage *steam_remote_storage;
	struct ISteamScreenshots *steam_screenshots;
	struct ISteamHTTP *steam_http;
	struct ISteamUnifiedMessages *steam_unified_messages;
	struct ISteamController *steam_controller;
	struct ISteamUGC *steam_ugc;
	struct ISteamAppList *steam_app_list;
	struct ISteamMusic *steam_music;
	struct ISteamMusicRemote *steam_music_remote;
	struct ISteamHTMLSurface *steam_html_surface;
	struct ISteamInventory *steam_inventory;
	struct ISteamVideo *steam_video;
	struct ISteamParentalSettings *steam_parental_settings;
};

struct CSteamAPIContextInitData
{
	void (*callback)(struct CSteamAPIContext *ctx);
	uintptr_t counter;
	struct CSteamAPIContext ctx;
};

extern steam_bool_t SteamAPI_Init(void);
extern steam_bool_t SteamAPI_InitSafe(void);
extern steam_bool_t SteamAPI_IsSteamRunning(void);
extern void SteamAPI_Shutdown(void);
extern steam_bool_t SteamAPI_RestartAppIfNecessary(steam_app_id_t app_id);
extern void SteamAPI_RunCallbacks(void);
extern void SteamAPI_WriteMiniDump(uint32_t excp_code, void *excp_info, uint32_t build_id);
extern void SteamAPI_SetMiniDumpComment(const char *msg);
extern void SteamAPI_RegisterCallback(struct CCallbackBase *callback, enum steam_callback_type type);
extern void SteamAPI_UnregisterCallback(struct CCallbackBase *callback);
extern void SteamAPI_RegisterCallResult(struct CCallbackBase *callback, steam_api_call_t api_call);
extern void SteamAPI_UnregisterCallResult(struct CCallbackBase *callback, steam_api_call_t api_call);
extern steam_handle_pipe_t SteamAPI_GetHSteamPipe(void);
extern steam_handle_pipe_t GetHSteamPipe(void);
extern steam_user_t SteamAPI_GetHSteamUser(void);
extern steam_user_t GetHSteamUser(void);
extern void SteamAPI_SetTryCatchCallbacks(steam_bool_t enable);
extern void SteamAPI_UseBreakpadCrashHandler(const char *version, const char *date, char const *time, steam_bool_t is_full_memory_dump, void *context, void *pre_minidump_callback);
extern void *SteamInternal_CreateInterface(const char *version);
extern struct CSteamAPIContext *SteamInternal_ContextInit(struct CSteamAPIContextInitData *data);

#endif /* STEAM_API_H */
