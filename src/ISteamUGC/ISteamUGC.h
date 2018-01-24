#ifndef ISTEAMUGC_H
#define ISTEAMUGC_H 1

#define STEAMUGC_INTERFACE_VERSION_PREFIX "STEAMUGC_INTERFACE_VERSION"

struct ISteamUGC
{
	const void *iface;
};

struct ISteamUGC *SteamUGC_generic(const char *version);
extern struct ISteamUGC *SteamUGC(void);

#endif /* ISTEAMUGC_H */
