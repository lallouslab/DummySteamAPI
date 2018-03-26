#ifndef ISTEAMUSER_H
#define ISTEAMUSER_H 1

#define STEAMUSER_INTERFACE_VERSION_PREFIX "SteamUser"

struct ISteamUser
{
	union
	{
		const void *ptr;
		const struct ISteamUser004Vtbl *v004;
		const struct ISteamUser017Vtbl *v017;
		const struct ISteamUser018Vtbl *v018;
	} vtbl;
};

struct ISteamUser *SteamUser_generic(const char *version);
void SteamUser_set_version(const char *version);
extern struct ISteamUser *SteamUser(void);

#endif /* ISTEAMUSER_H */
