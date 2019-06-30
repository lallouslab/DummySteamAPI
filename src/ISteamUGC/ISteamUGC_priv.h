#ifndef ISTEAMUGC_PRIV_H
#define ISTEAMUGC_PRIV_H 1

#include "steam.h"

#include "ISteamUGC.h"
#include "../ISteamRemoteStorage/ISteamRemoteStorage.h"

struct ISteamUGCImpl
{
	struct ISteamUGC base;
};

static inline struct ISteamUGCImpl *impl_from_ISteamUGC(struct ISteamUGC *iface) {
	return CONTAINER_OF(iface, struct ISteamUGCImpl, base);
}

MEMBER steam_ugc_query_handle_t ISteamUGC_CreateQueryUGCDetailsRequest(struct ISteamUGC *iface, steam_published_file_id_t *ids, uint32_t max_ids);
MEMBER steam_api_call_t ISteamUGC_SendQueryUGCRequest(struct ISteamUGC *iface, steam_ugc_query_handle_t handle);
MEMBER steam_bool_t ISteamUGC_ReleaseQueryUGCRequest(struct ISteamUGC *iface, steam_ugc_query_handle_t handle);
MEMBER steam_bool_t ISteamUGC_SetReturnOnlyIDs(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_only_ids);
MEMBER steam_bool_t ISteamUGC_SetReturnKeyValueTags(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_kv_tags);
MEMBER steam_bool_t ISteamUGC_SetReturnLongDescription(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_long_desc);
MEMBER steam_bool_t ISteamUGC_SetReturnMetadata(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_metadata);
MEMBER steam_bool_t ISteamUGC_SetReturnChildren(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_children);
MEMBER steam_bool_t ISteamUGC_SetReturnAdditionalPreviews(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_additional_previews);
MEMBER steam_bool_t ISteamUGC_SetReturnTotalOnly(struct ISteamUGC *iface, steam_ugc_query_handle_t handle, steam_bool_t return_total_only);
MEMBER uint32_t ISteamUGC_GetNumSubscribedItems(struct ISteamUGC *iface);
MEMBER uint32_t ISteamUGC_GetSubscribedItems(struct ISteamUGC *iface, steam_published_file_id_t *ids, uint32_t max_ids);

#endif /* ISTEAMUGC_PRIV_H */
