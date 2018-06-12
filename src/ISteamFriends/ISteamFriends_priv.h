#ifndef ISTEAMFRIENDS_PRIV_H
#define ISTEAMFRIENDS_PRIV_H 1

#include "steam.h"

#include "ISteamFriends.h"

struct ISteamFriendsImpl
{
	struct ISteamFriends base;
};

static inline struct ISteamFriendsImpl *impl_from_ISteamFriends(struct ISteamFriends *iface) {
	return CONTAINER_OF(iface, struct ISteamFriendsImpl, base);
}

MEMBER const char *ISteamFriends_GetPersonaName(struct ISteamFriends *iface);
MEMBER steam_api_call_t ISteamFriends_SetPersonaName(struct ISteamFriends *iface, const char *name);
MEMBER uint32_t ISteamFriends_GetPersonaState(struct ISteamFriends *iface);
MEMBER int ISteamFriends_GetFriendCount(struct ISteamFriends *iface, int flags);
MEMBER const char *ISteamFriends_GetFriendPersonaName(struct ISteamFriends *iface, union CSteamID steam_id_friend);
MEMBER int ISteamFriends_GetSmallFriendAvatar(struct ISteamFriends *iface, union CSteamID steam_id_friend);
MEMBER int ISteamFriends_GetMediumFriendAvatar(struct ISteamFriends *iface, union CSteamID steam_id_friend);
MEMBER int ISteamFriends_GetLargeFriendAvatar(struct ISteamFriends *iface, union CSteamID steam_id_friend);
MEMBER steam_bool_t ISteamFriends_GetFriendGamePlayed(struct ISteamFriends *iface, union CSteamID steam_id_friend, void /* FriendGameInfo_t */ *friend_game_info);
MEMBER steam_bool_t ISteamFriends_SetRichPresence(struct ISteamFriends *iface, const char *key, const char *value);
MEMBER steam_bool_t ISteamFriends_InviteUserToGame(struct ISteamFriends *iface, union CSteamID steam_id_friend, const char *connect_str);

#endif /* ISTEAMFRIENDS_PRIV_H */
