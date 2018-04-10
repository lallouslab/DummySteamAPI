#ifndef ISTEAMUSER_PRIV_H
#define ISTEAMUSER_PRIV_H 1

#include "steam.h"

#include "ISteamUser.h"

struct ISteamUserImpl
{
	struct ISteamUser base;
};

static inline struct ISteamUserImpl *impl_from_ISteamUser(struct ISteamUser *iface) {
	return CONTAINER_OF(iface, struct ISteamUserImpl, base);
}

MEMBER steam_user_t ISteamUser_GetHSteamUser(struct ISteamUser *iface);
MEMBER steam_bool_t ISteamUser_BLoggedOn(struct ISteamUser *iface);
DSA_MEMBER_RETURN_STRUCT0(union CSteamID, ret, ISteamUser_GetSteamID, struct ISteamUser *iface);
MEMBER int ISteamUser_InitiateGameConnection(struct ISteamUser *iface, void *auth_blob, int auth_blob_size, union CSteamID steam_id_game_server, steam_app_id_t app_id, uint32_t server_ip, uint16_t server_port, steam_bool_t secure);
MEMBER int ISteamUser_InitiateGameConnection010(struct ISteamUser *iface, void *auth_blob, int auth_blob_size, union CSteamID steam_id_game_server, uint32_t server_ip, uint16_t server_port, steam_bool_t secure);
MEMBER void ISteamUser_TerminateGameConnection(struct ISteamUser *iface, uint32_t server_ip, uint16_t server_port);
MEMBER steam_bool_t ISteamUser_GetUserDataFolder(struct ISteamUser *iface, char *buf, int buf_len);
MEMBER steam_auth_ticket_handle_t ISteamUser_GetAuthSessionTicket(struct ISteamUser *iface, void *buf, int buf_size, uint32_t *ticket_len);
MEMBER void ISteamUser_CancelAuthTicket(struct ISteamUser *iface, steam_auth_ticket_handle_t ticket_handle);
MEMBER void ISteamUser_AdvertiseGame(struct ISteamUser *iface, union CSteamID steam_id_game_server, uint32_t server_ip, uint16_t server_port);
MEMBER steam_api_call_t ISteamUser_RequestEncryptedAppTicket(struct ISteamUser *iface, void *data, int data_size);

#endif /* ISTEAMUSER_PRIV_H */
