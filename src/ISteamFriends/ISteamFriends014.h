#ifndef ISTEAMFRIENDS014_H
#define ISTEAMFRIENDS014_H 1

#include "steam.h"

#include "ISteamFriends.h"

#define STEAMFRIENDS_INTERFACE_VERSION_014 "SteamFriends014"

struct ISteamFriends014
{
	const char *(*GetPersonaName)(struct ISteamFriendsImpl *This);
	void *SetPersonaName;
	uint32_t (*GetPersonaState)(struct ISteamFriendsImpl *This);
	int (*GetFriendCount)(struct ISteamFriendsImpl *This, int friend_flags);
	void *GetFriendByIndex;
	void *GetFriendRelationship;
	void *GetFriendPersonaState;
	const char *(*GetFriendPersonaName)(struct ISteamFriendsImpl *This, void /* CSteamID */ *steam_id_friend);
	void *GetFriendGamePlayed3;
	void *GetFriendPersonaNameHistory;
	void *GetPlayerNickname;
	void *HasFriend;
	void *GetClanCount;
	void *GetClanByIndex;
	void *GetClanName;
	void *GetClanTag;
	void *GetClanActivityCounts;
	void *DownloadClanActivityCounts;
	void *GetFriendCountFromSource;
	void *GetFriendFromSourceByIndex;
	void *IsUserInSource;
	void *SetInGameVoiceSpeaking;
	void *ActivateGameOverlay;
	void *ActivateGameOverlayToUser;
	void *ActivateGameOverlayToWebPage;
	void *ActivateGameOverlayToStore;
	void *SetPlayedWith;
	void *ActivateGameOverlayInviteDialog;
	void *GetSmallFriendAvatar;
	void *GetMediumFriendAvatar;
	void *GetLargeFriendAvatar;
	void *RequestUserInformation;
	void *RequestClanOfficerList;
	void *GetClanOwner;
	void *GetClanOfficerCount;
	void *GetClanOfficerByIndex;
	void *GetUserRestrictions;
	void *SetRichPresence;
	void *ClearRichPresence;
	void *GetFriendRichPresence;
	void *GetFriendRichPresenceKeyCount;
	void *GetFriendRichPresenceKeyByIndex;
	void *RequestFriendRichPresence;
	steam_bool_t (*InviteUserToGame)(struct ISteamFriendsImpl *This, void /* CSteamID */ *steam_id_friend, const char *connect_str);
	void *GetCoplayFriendCount;
	void *GetCoplayFriend;
	void *GetFriendCoplayTime;
	void *GetFriendCoplayGame;
	void *JoinClanChatRoom;
	void *LeaveClanChatRoom;
	void *GetClanChatMemberCount;
	void *GetChatMemberByIndex;
	void *SendClanChatMessage;
	void *GetClanChatMessage;
	void *IsClanChatAdmin;
	void *IsClanChatWindowOpenInSteam;
	void *OpenClanChatWindowInSteam;
	void *CloseClanChatWindowInSteam;
	void *SetListenForFriendsMessages;
	void *ReplyToFriendMessage;
	void *GetFriendMessage;
	void *GetFollowerCount;
	void *IsFollowing;
	void *EnumerateFollowingList;
};

struct ISteamFriendsImpl *SteamFriends014(void);

#endif /* ISTEAMFRIENDS014_H */
