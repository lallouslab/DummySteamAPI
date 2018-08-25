#ifndef ISTEAMUSER_H
#define ISTEAMUSER_H 1

#include "steam.h"

#define STEAMUSER_INTERFACE_VERSION_PREFIX "SteamUser"

struct ISteamUser
{
	union
	{
		const void *ptr;
		const struct ISteamUser004Vtbl *v004;
		const struct ISteamUser016Vtbl *v016;
		const struct ISteamUser017Vtbl *v017;
		const struct ISteamUser018Vtbl *v018;
		const struct ISteamUser019Vtbl *v019;
	} vtbl;
};

typedef uint32_t steam_auth_ticket_handle_t;

PACKED_STRUCT steam_callback_data_user_encrypted_app_ticket_response
{
	enum steam_result result;
};

PACKED_STRUCT steam_callback_data_user_get_auth_session_ticket_response
{
	steam_auth_ticket_handle_t ticket;
	enum steam_result result;
};

struct ISteamUser *SteamUser_generic(const char *version);
void SteamUser_set_version(const char *version);
extern struct ISteamUser *SteamUser(void);

#endif /* ISTEAMUSER_H */
