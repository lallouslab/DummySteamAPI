#ifndef ISTEAMAPPS_H
#define ISTEAMAPPS_H 1

#define STEAMAPPS_INTERFACE_VERSION_PREFIX "STEAMAPPS_INTERFACE_VERSION"

struct ISteamApps
{
	union
	{
		const void *ptr;
		const struct ISteamApps001Vtbl *v001;
		const struct ISteamApps003Vtbl *v003;
		const struct ISteamApps006Vtbl *v006;
		const struct ISteamApps007Vtbl *v007;
	} vtbl;
};

struct ISteamApps *SteamApps_generic(const char *version);
void SteamApps_set_version(const char *version);
extern struct ISteamApps *SteamApps(void);

#endif /* ISTEAMAPPS_H */
