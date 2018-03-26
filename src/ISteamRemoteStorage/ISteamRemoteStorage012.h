#ifndef ISTEAMREMOTESTORAGE012_H
#define ISTEAMREMOTESTORAGE012_H 1

#include "steam.h"

#include "ISteamRemoteStorage.h"

#define STEAMREMOTESTORAGE_INTERFACE_VERSION_012 "STEAMREMOTESTORAGE_INTERFACE_VERSION012"

struct ISteamRemoteStorage012Vtbl
{
	steam_bool_t (*FileWrite)(struct ISteamRemoteStorage *iface, const char *filename, const void *data, int32_t size);
	void *FileRead;
	void *FileForget;
	void *FileDelete;
	void *FileShare;
	void *SetSyncPlatforms;
	void *FileWriteStreamOpen;
	void *FileWriteStreamWriteChunk;
	void *FileWriteStreamClose;
	void *FileWriteStreamCancel;
	void *FileExists;
	void *FilePersisted;
	int32_t (*GetFileSize)(struct ISteamRemoteStorage *iface, const char *filename);
	void *GetFileTimestamp;
	void *GetSyncPlatforms;
	int32_t (*GetFileCount)(struct ISteamRemoteStorage *iface);
	void *GetFileNameAndSize;
	steam_bool_t (*GetQuota)(struct ISteamRemoteStorage *iface, int32_t *total_bytes, int32_t *available_bytes);
	void *IsCloudEnabledForAccount;
	void *IsCloudEnabledForApp;
	void (*SetCloudEnabledForApp)(struct ISteamRemoteStorage *iface, steam_bool_t enabled);
	void *UGCDownload;
	void *GetUGCDownloadProgress;
	void *GetUGCDetails;
	void *UGCRead;
	void *GetCachedUGCCount;
	void *GetCachedUGCHandle;
	void *PublishWorkshopFile;
	void *CreatePublishedFileUpdateRequest;
	void *UpdatePublishedFileFile;
	void *UpdatePublishedFilePreviewFile;
	void *UpdatePublishedFileTitle;
	void *UpdatePublishedFileDescription;
	void *UpdatePublishedFileVisibility;
	void *UpdatePublishedFileTags;
	void *CommitPublishedFileUpdate;
	void *GetPublishedFileDetails;
	void *DeletePublishedFile;
	void *EnumerateUserPublishedFiles;
	void *SubscribePublishedFile;
	void *EnumerateUserSubscribedFiles;
	void *UnsubscribePublishedFile;
	void *UpdatePublishedFileSetChangeDescription;
	void *GetPublishedItemVoteDetails;
	void *UpdateUserPublishedItemVote;
	void *GetUserPublishedItemVoteDetails;
	void *EnumerateUserSharedWorkshopFiles;
	void *PublishVideo;
	void *SetUserPublishedFileAction;
	void *EnumeratePublishedFilesByUserAction;
	void *EnumeratePublishedWorkshopFiles;
	void *UGCDownloadToLocation;
};

struct ISteamRemoteStorage *SteamRemoteStorage012(void);

#endif /* ISTEAMREMOTESTORAGE012_H */
