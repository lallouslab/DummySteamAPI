#ifndef ISTEAMREMOTESTORAGE013_H
#define ISTEAMREMOTESTORAGE013_H 1

#include "steam.h"

#include "ISteamRemoteStorage.h"

#define STEAMREMOTESTORAGE_INTERFACE_VERSION_013 "STEAMREMOTESTORAGE_INTERFACE_VERSION013"

struct ISteamRemoteStorage013Vtbl
{
	MEMBER steam_bool_t (*FileWrite)(struct ISteamRemoteStorage *iface, const char *filename, const void *data, int32_t size);
	void *FileRead;
	void *FileWriteAsync;
	void *FileReadAsync;
	void *FileReadAsyncComplete;
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
	MEMBER int32_t (*GetFileSize)(struct ISteamRemoteStorage *iface, const char *filename);
	void *GetFileTimestamp;
	void *GetSyncPlatforms;
	MEMBER int32_t (*GetFileCount)(struct ISteamRemoteStorage *iface);
	void *GetFileNameAndSize;
	MEMBER steam_bool_t (*GetQuota)(struct ISteamRemoteStorage *iface, int32_t *total_bytes, int32_t *available_bytes);
	void *IsCloudEnabledForAccount;
	void *IsCloudEnabledForApp;
	MEMBER void (*SetCloudEnabledForApp)(struct ISteamRemoteStorage *iface, steam_bool_t enabled);
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
	MEMBER steam_api_call_t (*EnumerateUserPublishedFiles)(struct ISteamRemoteStorage *iface, uint32_t start_idx);
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
	MEMBER steam_api_call_t (*EnumeratePublishedFilesByUserAction)(struct ISteamRemoteStorage *iface, enum steam_workshop_file_action action, uint32_t start_idx);
	void *EnumeratePublishedWorkshopFiles;
	void *UGCDownloadToLocation;
};

struct ISteamRemoteStorage *SteamRemoteStorage013(void);

#endif /* ISTEAMREMOTESTORAGE013_H */
