#ifndef ISTEAMUSER_PRIV_H
#define ISTEAMUSER_PRIV_H 1

#include "steam.h"

struct ISteamUserImpl
{
	const void *iface;
};

steam_user_t ISteamUser_GetHSteamUser(struct ISteamUserImpl *This);
steam_bool_t ISteamUser_BLoggedOn(struct ISteamUserImpl *This);
void ISteamUser_GetSteamID(union CSteamID *ret, struct ISteamUserImpl *This);
union CSteamID ISteamUser_GetSteamID018(struct ISteamUserImpl *This);
steam_bool_t ISteamUser_GetUserDataFolder(struct ISteamUserImpl *This, char *buf, int buf_len);
steam_api_call_t ISteamUser_RequestEncryptedAppTicket(struct ISteamUserImpl *This, void *data, int data_size);

#endif /* ISTEAMUSER_PRIV_H */
