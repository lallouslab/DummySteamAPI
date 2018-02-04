#ifndef ISTEAMFRIENDS001_H
#define ISTEAMFRIENDS001_H 1

#include "steam.h"

#include "ISteamFriends.h"

#define STEAMFRIENDS_INTERFACE_VERSION_001 "SteamFriends001"

struct ISteamFriends001Vtbl
{
	const char *(*GetPersonaName)(struct ISteamFriends *iface);
	void *SetPersonaName;
	uint32_t (*GetPersonaState)(struct ISteamFriends *iface);
	void *SetPersonaState;
	void *AddFriend;
	void *RemoveFriend;
	void *HasFriend;
	void *GetFriendRelationship;
	void *GetFriendPersonaState;
	void *GetFriendGamePlayed0;
	const char *(*GetFriendPersonaName)(struct ISteamFriends *iface, void /* CSteamID */ *steam_id_friend);
	void *AddFriendByName;
	void *GetFriendCount;
	void *GetFriendByIndex;
	void *SendMsgToFriend0;
	void *SetFriendRegValue;
	void *GetFriendRegValue;
	void *GetFriendPersonaNameHistory;
	void *GetChatMessage;
	void *SendMsgToFriend1;
	void *GetChatIDOfChatHistoryStart;
	void *SetChatHistoryStart;
	void *ClearChatHistory;
	void *InviteFriendByEmail;
	void *GetBlockedFriendCount;
	void *GetFriendGamePlayed1;
	void *GetFriendGamePlayed2;
};

static inline struct ISteamFriends001Vtbl *get_ISteamFriends001Vtbl_from_ISteamApps(struct ISteamFriends *iface) {
	return (struct ISteamFriends001Vtbl *)iface->vtbl;
}

struct ISteamFriends *SteamFriends001(void);

#endif /* ISTEAMFRIENDS001_H */