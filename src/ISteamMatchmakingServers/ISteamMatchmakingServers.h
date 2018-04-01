#ifndef ISTEAMMATCHMAKINGSERVERS_H
#define ISTEAMMATCHMAKINGSERVERS_H 1

#define STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_PREFIX "SteamMatchMakingServers"

struct ISteamMatchmakingServers
{
	union
	{
		const void *ptr;
		const struct ISteamMatchmakingServers001Vtbl *v001;
		const struct ISteamMatchmakingServers002Vtbl *v002;
	} vtbl;
};

typedef void *steam_handle_server_list_request_t;

struct ISteamMatchmakingServers *SteamMatchmakingServers_generic(const char *version);
void SteamMatchmakingServers_set_version(const char *version);
extern struct ISteamMatchmakingServers *SteamMatchmakingServers(void);

#endif /* ISTEAMMATCHMAKINGSERVERS_H */
