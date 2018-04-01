#ifndef ISTEAMUGC010_H
#define ISTEAMUGC010_H 1

#include "steam.h"

#include "ISteamUGC.h"

#define STEAMUGC_INTERFACE_VERSION_010 "STEAMUGC_INTERFACE_VERSION010"

struct ISteamUGC010Vtbl
{
	void *CreateQueryUserUGCRequest;
	void *CreateQueryAllUGCRequest;
	void *CreateQueryUGCDetailsRequest;
	void *SendQueryUGCRequest;
	void *GetQueryUGCResult;
	void *GetQueryUGCPreviewURL;
	void *GetQueryUGCMetadata;
	void *GetQueryUGCChildren;
	void *GetQueryUGCStatistic;
	void *GetQueryUGCNumAdditionalPreviews;
	void *GetQueryUGCAdditionalPreview;
	void *GetQueryUGCNumKeyValueTags;
	void *GetQueryUGCKeyValueTag;
	void *ReleaseQueryUGCRequest;
	void *AddRequiredTag;
	void *AddExcludedTag;
	void *SetReturnOnlyIDs;
	void *SetReturnKeyValueTags;
	void *SetReturnLongDescription;
	void *SetReturnMetadata;
	void *SetReturnChildren;
	void *SetReturnAdditionalPreviews;
	void *SetReturnTotalOnly;
	void *SetReturnPlaytimeStats;
	void *SetLanguage;
	void *SetAllowCachedResponse;
	void *SetCloudFileNameFilter;
	void *SetMatchAnyTag;
	void *SetSearchText;
	void *SetRankedByTrendDays;
	void *AddRequiredKeyValueTag;
	void *RequestUGCDetails;
	void *CreateItem;
	void *StartItemUpdate;
	void *SetItemTitle;
	void *SetItemDescription;
	void *SetItemUpdateLanguage;
	void *SetItemMetadata;
	void *SetItemVisibility;
	void *SetItemTags;
	void *SetItemContent;
	void *SetItemPreview;
	void *RemoveItemKeyValueTags;
	void *AddItemKeyValueTag;
	void *AddItemPreviewFile;
	void *AddItemPreviewVideo;
	void *UpdateItemPreviewFile;
	void *UpdateItemPreviewVideo;
	void *RemoveItemPreview;
	void *SubmitItemUpdate;
	void *GetItemUpdateProgress;
	void *SetUserItemVote;
	void *GetUserItemVote;
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
	void *BInitWorkshopForGameServer;
	void *SuspendDownloads;
	void *StartPlaytimeTracking;
	void *StopPlaytimeTracking;
	void *StopPlaytimeTrackingForAllItems;
	void *AddDependency;
	void *RemoveDependency;
	void *AddAppDependency;
	void *RemoveAppDependency;
	void *GetAppDependencies;
	void *DeleteItem;
};

struct ISteamUGC *SteamUGC010(void);

#endif /* ISTEAMUGC010_H */