#ifndef ISTEAMUGC005_H
#define ISTEAMUGC005_H 1

#include "steam.h"

#include "ISteamUGC.h"
#include "../ISteamRemoteStorage/ISteamRemoteStorage.h"

#define STEAMUGC_INTERFACE_VERSION_005 "STEAMUGC_INTERFACE_VERSION005"

struct ISteamUGC005Vtbl
{
	void *CreateQueryUserUGCRequest;
	void *CreateQueryAllUGCRequest;
	MEMBER steam_ugc_query_handle_t (*CreateQueryUGCDetailsRequest)(struct ISteamUGC *iface, steam_published_file_id_t *ids, uint32_t max_ids);
	MEMBER steam_api_call_t (*SendQueryUGCRequest)(struct ISteamUGC *iface, steam_ugc_query_handle_t handle);
	void *GetQueryUGCResult;
	void *GetQueryUGCPreviewURL;
	void *GetQueryUGCMetadata;
	void *GetQueryUGCChildren;
	void *GetQueryUGCStatistic;
	void *GetQueryUGCNumAdditionalPreviews;
	void *GetQueryUGCAdditionalPreview;
	MEMBER steam_bool_t (*ReleaseQueryUGCRequest)(struct ISteamUGC *iface, steam_ugc_query_handle_t handle);
	void *AddRequiredTag;
	void *AddExcludedTag;
	void *SetReturnLongDescription;
	void *SetReturnMetadata;
	MEMBER steam_bool_t (*SetReturnChildren)(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_children);
	MEMBER steam_bool_t (*SetReturnAdditionalPreviews)(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_additional_previews);
	MEMBER steam_bool_t (*SetReturnTotalOnly)(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_total_only);
	void *SetAllowCachedResponse;
	void *SetCloudFileNameFilter;
	void *SetMatchAnyTag;
	void *SetSearchText;
	void *SetRankedByTrendDays;
	void *RequestUGCDetails;
	void *CreateItem;
	void *StartItemUpdate;
	void *SetItemTitle;
	void *SetItemDescription;
	void *SetItemMetadata;
	void *SetItemVisibility;
	void *SetItemTags;
	void *SetItemContent;
	void *SetItemPreview;
	void *SubmitItemUpdate;
	void *GetItemUpdateProgress;
	void *AddItemToFavorites;
	void *RemoveItemFromFavorites;
	void *SubscribeItem;
	void *UnsubscribeItem;
	MEMBER uint32_t (*GetNumSubscribedItems)(struct ISteamUGC *iface);
	void *GetSubscribedItems;
	void *GetItemState;
	void *GetItemInstallInfo;
	void *GetItemDownloadInfo;
	void *DownloadItem;
};

struct ISteamUGC *SteamUGC005(void);

#endif /* ISTEAMUGC005_H */
