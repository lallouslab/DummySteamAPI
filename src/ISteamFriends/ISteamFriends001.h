#ifndef ISTEAMFRIENDS001_H
#define ISTEAMFRIENDS001_H 1

#include "steam.h"

#include "ISteamFriends.h"

#define STEAMFRIENDS_INTERFACE_VERSION_001 "SteamFriends001"

struct ISteamFriends001Vtbl
{
	MEMBER const char *(*GetPersonaName)(struct ISteamFriends *iface);
	void *SetPersonaName;
	MEMBER uint32_t (*GetPersonaState)(struct ISteamFriends *iface);
	void *SetPersonaState;
	void *AddFriend;
	void *RemoveFriend;
	void *HasFriend;
	void *GetFriendRelationship;
	void *GetFriendPersonaState;
	void *GetFriendGamePlayed0;
	MEMBER const char *(*GetFriendPersonaName)(struct ISteamFriends *iface, union CSteamID steam_id_friend);
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

struct ISteamFriends *SteamFriends001(void);

#endif /* ISTEAMFRIENDS001_H */
