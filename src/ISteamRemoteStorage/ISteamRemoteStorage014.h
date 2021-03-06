#ifndef ISTEAMREMOTESTORAGE014_H
#define ISTEAMREMOTESTORAGE014_H 1

#include "steam.h"

#include "ISteamRemoteStorage.h"

#define STEAMREMOTESTORAGE_INTERFACE_VERSION_014 "STEAMREMOTESTORAGE_INTERFACE_VERSION014"

struct ISteamRemoteStorage014Vtbl
{
	MEMBER steam_bool_t (*FileWrite)(struct ISteamRemoteStorage *iface, const char *filename, const void *data, int32_t size);
	MEMBER int32_t (*FileRead)(struct ISteamRemoteStorage *iface, const char *filename, void *data, int32_t size);
	void *FileWriteAsync;
	void *FileReadAsync;
	void *FileReadAsyncComplete;
	void *FileForget;
	void *FileDelete;
	void *FileShare;
	void *SetSyncPlatforms;
	MEMBER steam_ugc_file_write_stream_handle_t (*FileWriteStreamOpen)(struct ISteamRemoteStorage *iface, const char *filename);
	MEMBER steam_bool_t (*FileWriteStreamWriteChunk)(struct ISteamRemoteStorage *iface, steam_ugc_file_write_stream_handle_t handle, void *data, int32_t size);
	MEMBER steam_bool_t (*FileWriteStreamClose)(struct ISteamRemoteStorage *iface, steam_ugc_file_write_stream_handle_t handle);
	MEMBER steam_bool_t (*FileWriteStreamCancel)(struct ISteamRemoteStorage *iface, steam_ugc_file_write_stream_handle_t handle);
	MEMBER steam_bool_t (*FileExists)(struct ISteamRemoteStorage *iface, const char *filename);
	void *FilePersisted;
	MEMBER int32_t (*GetFileSize)(struct ISteamRemoteStorage *iface, const char *filename);
	MEMBER int64_t (*GetFileTimestamp)(struct ISteamRemoteStorage *iface, const char *filename);
	void *GetSyncPlatforms;
	MEMBER int32_t (*GetFileCount)(struct ISteamRemoteStorage *iface);
	void *GetFileNameAndSize;
	MEMBER steam_bool_t (*GetQuota)(struct ISteamRemoteStorage *iface, uint64_t *total_bytes, uint64_t *available_bytes);
	MEMBER steam_bool_t (*IsCloudEnabledForAccount)(struct ISteamRemoteStorage *iface);
	MEMBER steam_bool_t (*IsCloudEnabledForApp)(struct ISteamRemoteStorage *iface);
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
	MEMBER steam_api_call_t (*EnumerateUserSubscribedFiles)(struct ISteamRemoteStorage *iface, uint32_t start_idx);
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

struct ISteamRemoteStorage *SteamRemoteStorage014(void);

#endif /* ISTEAMREMOTESTORAGE014_H */
