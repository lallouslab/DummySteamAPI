#ifndef ISTEAMUSER_H
#define ISTEAMUSER_H 1

#define STEAMUSER_INTERFACE_VERSION_PREFIX "SteamUser"

struct ISteamUserImpl;

struct ISteamUserImpl *SteamUser_generic(const char *version);
extern struct ISteamUserImpl *SteamUser(void);

#endif /* ISTEAMUSER_H */
