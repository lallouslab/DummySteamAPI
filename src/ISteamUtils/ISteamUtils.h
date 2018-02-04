#ifndef ISTEAMUTILS_H
#define ISTEAMUTILS_H 1

#define STEAMUTILS_INTERFACE_VERSION_PREFIX "SteamUtils"

struct ISteamUtils
{
	const void *vtbl;
};

struct ISteamUtils *SteamUtils_generic(const char *version);
extern struct ISteamUtils *SteamUtils(void);

#endif /* ISTEAMUTILS_H */
