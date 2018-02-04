#ifndef ISTEAMSCREENSHOTS_H
#define ISTEAMSCREENSHOTS_H 1

#define STEAMSCREENSHOTS_INTERFACE_VERSION_PREFIX "STEAMSCREENSHOTS_INTERFACE_VERSION"

struct ISteamScreenshots
{
	const void *vtbl;
};

extern struct ISteamScreenshots *SteamScreenshots_generic(const char *version);
extern struct ISteamScreenshots *SteamScreenshots(void);

#endif /* ISTEAMSCREENSHOTS_H */
