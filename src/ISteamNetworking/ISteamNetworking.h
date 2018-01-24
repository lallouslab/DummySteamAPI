#ifndef ISTEAMNETWORKING_H
#define ISTEAMNETWORKING_H 1

#define STEAMNETWORKING_INTERFACE_VERSION_PREFIX "SteamNetworking"

struct ISteamNetworkingImpl;

struct ISteamNetworkingImpl *SteamNetworking_generic(const char *version);
extern struct ISteamNetworkingImpl *SteamNetworking(void);

#endif /* ISTEAMNETWORKING_H */
