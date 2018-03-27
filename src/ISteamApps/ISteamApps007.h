#ifndef ISTEAMAPPS007_H
#define ISTEAMAPPS007_H 1

#include "steam.h"

#include "ISteamApps.h"

#define STEAMAPPS_INTERFACE_VERSION_007 "STEAMAPPS_INTERFACE_VERSION007"

struct ISteamApps007Vtbl
{
	MEMBER steam_bool_t (*BIsSubscribed)(struct ISteamApps *iface);
	MEMBER steam_bool_t (*BIsLowViolence)(struct ISteamApps *iface);
	MEMBER steam_bool_t (*BIsCybercafe)(struct ISteamApps *iface);
	MEMBER steam_bool_t (*BIsVACBanned)(struct ISteamApps *iface);
	MEMBER const char *(*GetCurrentGameLanguage)(struct ISteamApps *iface);
	MEMBER const char *(*GetAvailableGameLanguages)(struct ISteamApps *iface);
	MEMBER steam_bool_t (*BIsSubscribedApp)(struct ISteamApps *iface, steam_app_id_t app_id);
	MEMBER steam_bool_t (*BIsDlcInstalled)(struct ISteamApps *iface, steam_app_id_t app_id);
	void *GetEarliestPurchaseUnixTime;
	void *BIsSubscribedFromFreeWeekend;
	void *GetDLCCount;
	void *BGetDLCDataByIndex;
	void *InstallDLC;
	void *UninstallDLC;
	void *RequestAppProofOfPurchaseKey;
	void *GetCurrentBetaName;
	void *MarkContentCorrupt;
	void *GetInstalledDepots;
	void *GetAppInstallDir;
	void *BIsAppInstalled;
	void *GetAppOwner;
	void *GetLaunchQueryParam;
	void *GetDlcDownloadProgress;
	void *GetAppBuildId;
	void *RequestAllProofOfPurchaseKeys;
};

struct ISteamApps *SteamApps007(void);

#endif /* ISTEAMAPPS007_H */
