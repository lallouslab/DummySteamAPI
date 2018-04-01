#ifndef ISTEAMSCREENSHOTS_H
#define ISTEAMSCREENSHOTS_H 1

#define STEAMSCREENSHOTS_INTERFACE_VERSION_PREFIX "STEAMSCREENSHOTS_INTERFACE_VERSION"

struct ISteamScreenshots
{
	union
	{
		const void *ptr;
		const struct ISteamScreenshots001Vtbl *v001;
		const struct ISteamScreenshots002Vtbl *v002;
		const struct ISteamScreenshots003Vtbl *v003;
	} vtbl;
};

extern struct ISteamScreenshots *SteamScreenshots_generic(const char *version);
void SteamScreenshots_set_version(const char *version);
extern struct ISteamScreenshots *SteamScreenshots(void);

#endif /* ISTEAMSCREENSHOTS_H */
