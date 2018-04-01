#ifndef ISTEAMUTILS_H
#define ISTEAMUTILS_H 1

#define STEAMUTILS_INTERFACE_VERSION_PREFIX "SteamUtils"

struct ISteamUtils
{
	union
	{
		const void *ptr;
		const struct ISteamUtils001Vtbl *v001;
		const struct ISteamUtils002Vtbl *v002;
		const struct ISteamUtils006Vtbl *v006;
		const struct ISteamUtils007Vtbl *v007;
		const struct ISteamUtils009Vtbl *v009;
	} vtbl;
};

enum steam_notification_position
{
	STEAM_NOTIFICATION_POSITION_TOP_LEFT = 0u,
	STEAM_NOTIFICATION_POSITION_TOP_RIGHT = 1u,
	STEAM_NOTIFICATION_POSITION_BOTTOM_LEFT = 2u,
	STEAM_NOTIFICATION_POSITION_BOTTOM_RIGHT = 3u
};

struct ISteamUtils *SteamUtils_generic(const char *version);
void SteamUtils_set_version(const char *version);
extern struct ISteamUtils *SteamUtils(void);

#endif /* ISTEAMUTILS_H */
