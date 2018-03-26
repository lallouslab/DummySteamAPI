#ifndef ISTEAMUTILS_H
#define ISTEAMUTILS_H 1

#define STEAMUTILS_INTERFACE_VERSION_PREFIX "SteamUtils"

struct ISteamUtils
{
	union
	{
		const void *ptr;
		const struct ISteamUtils001Vtbl *v001;
		const struct ISteamUtils006Vtbl *v006;
		const struct ISteamUtils007Vtbl *v007;
	} vtbl;
};

struct ISteamUtils *SteamUtils_generic(const char *version);
void SteamUtils_set_version(const char *version);
extern struct ISteamUtils *SteamUtils(void);

#endif /* ISTEAMUTILS_H */
