#ifndef ISTEAMSCREENSHOTS_H
#define ISTEAMSCREENSHOTS_H 1

#define STEAMSCREENSHOTS_INTERFACE_VERSION_PREFIX "STEAMSCREENSHOTS_INTERFACE_VERSION"

struct ISteamScreenshotsImpl;

extern struct ISteamScreenshotsImpl *SteamScreenshots_generic(const char *version);
extern struct ISteamScreenshotsImpl *SteamScreenshots(void);

#endif /* ISTEAMSCREENSHOTS_H */
