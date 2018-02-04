#ifndef ISTEAMAPPS_H
#define ISTEAMAPPS_H 1

#define STEAMAPPS_INTERFACE_VERSION_PREFIX "STEAMAPPS_INTERFACE_VERSION"

struct ISteamApps
{
	const void *vtbl;
};

struct ISteamApps *SteamApps_generic(const char *version);
extern struct ISteamApps *SteamApps(void);

#endif /* ISTEAMAPPS_H */
