#ifndef ISTEAMMUSIC_H
#define ISTEAMMUSIC_H 1

#define STEAMMUSIC_INTERFACE_VERSION_PREFIX "STEAMMUSIC_INTERFACE_VERSION"

struct ISteamMusic
{
	const void *vtbl;
};

struct ISteamMusic *SteamMusic_generic(const char *version);
void SteamMusic_set_version(const char *version);
extern struct ISteamMusic *SteamMusic(void);

#endif /* ISTEAMMUSIC_H */
