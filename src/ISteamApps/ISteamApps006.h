#ifndef ISTEAMAPPS006_H
#define ISTEAMAPPS006_H 1

#include "steam.h"

#include "ISteamApps.h"

#define STEAMAPPS_INTERFACE_VERSION_006 "STEAMAPPS_INTERFACE_VERSION006"

struct ISteamApps006Vtbl
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
};

static inline struct ISteamApps006Vtbl *get_ISteamApps006Vtbl_from_ISteamApps(struct ISteamApps *iface) {
	return (struct ISteamApps006Vtbl *)iface->vtbl;
}

struct ISteamApps *SteamApps006(void);

#endif /* ISTEAMAPPS006_H */
