#ifndef ISTEAMFRIENDS_PRIV_H
#define ISTEAMFRIENDS_PRIV_H 1

#include "steam.h"

struct ISteamFriendsImpl
{
	const void *iface;
};

const char *ISteamFriends_GetPersonaName(struct ISteamFriendsImpl *This);
steam_api_call_t ISteamFriends_SetPersonaName(struct ISteamFriendsImpl *This, const char *name);
uint32_t ISteamFriends_GetPersonaState(struct ISteamFriendsImpl *This);
int ISteamFriends_GetFriendCount(struct ISteamFriendsImpl *This, int flags);
const char *ISteamFriends_GetFriendPersonaName(struct ISteamFriendsImpl *This, void /* CSteamID */ *steam_id_friend);steam_bool_t ISteamFriends_GetFriendGamePlayed(struct ISteamFriendsImpl *This, void /* CSteamID */ *steam_id_friend, void /* FriendGameInfo_t */ *friend_game_info);
steam_bool_t ISteamFriends_InviteUserToGame(struct ISteamFriendsImpl *This, void /* CSteamID */ *steam_id_friend, const char *connect_str);

#endif /* ISTEAMFRIENDS_PRIV_H */
