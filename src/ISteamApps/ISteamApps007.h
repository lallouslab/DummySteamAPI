#ifndef ISTEAMAPPS007_H
#define ISTEAMAPPS007_H 1

#include "steam.h"

#include "ISteamApps.h"

#define STEAMAPPS_INTERFACE_VERSION_007 "STEAMAPPS_INTERFACE_VERSION007"

struct ISteamApps007Vtbl
{
	steam_bool_t (*BIsSubscribed)(struct ISteamApps *iface);
	steam_bool_t (*BIsLowViolence)(struct ISteamApps *iface);
	steam_bool_t (*BIsCybercafe)(struct ISteamApps *iface);
	steam_bool_t (*BIsVACBanned)(struct ISteamApps *iface);
	const char *(*GetCurrentGameLanguage)(struct ISteamApps *iface);
	const char *(*GetAvailableGameLanguages)(struct ISteamApps *iface);
	steam_bool_t (*BIsSubscribedApp)(struct ISteamApps *iface, steam_app_id_t app_id);
	steam_bool_t (*BIsDlcInstalled)(struct ISteamApps *iface, steam_app_id_t app_id);
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

static inline struct ISteamApps007Vtbl *get_ISteamApps007Vtbl_from_ISteamApps(struct ISteamApps *iface) {
	return (struct ISteamApps007Vtbl *)iface->vtbl;
}

struct ISteamApps *SteamApps007(void);

#endif /* ISTEAMAPPS007_H */
