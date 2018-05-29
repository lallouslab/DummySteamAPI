#ifndef ISTEAMMATCHMAKING_H
#define ISTEAMMATCHMAKING_H 1

#define STEAMMATCHMAKING_INTERFACE_VERSION_PREFIX "SteamMatchMaking"

struct ISteamMatchmaking
{
	union
	{
		const void *ptr;
		const struct ISteamMatchmaking001Vtbl *v001;
		const struct ISteamMatchmaking009Vtbl *v009;
	} vtbl;
};

PACKED_STRUCT steam_callback_data_matchmaking_lobby_created
{
	enum steam_result result;
	union CSteamID steam_id_lobby;
};

struct ISteamMatchmaking *SteamMatchmaking_generic(const char *version);
void SteamMatchmaking_set_version(const char *version);
extern struct ISteamMatchmaking *SteamMatchmaking(void);

#endif /* ISTEAMMATCHMAKING_H */
