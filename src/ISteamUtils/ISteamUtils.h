#ifndef ISTEAMUTILS_H
#define ISTEAMUTILS_H 1

#define STEAMUTILS_INTERFACE_VERSION_PREFIX "SteamUtils"

struct ISteamUtilsImpl;

struct ISteamUtilsImpl *SteamUtils_generic(const char *version);
extern struct ISteamUtilsImpl *SteamUtils(void);

#endif /* ISTEAMUTILS_H */
