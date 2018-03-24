#ifndef ISTEAMMUSICREMOTE_H
#define ISTEAMMUSICREMOTE_H 1

#define STEAMMUSICREMOTE_INTERFACE_VERSION_PREFIX "STEAMMUSICREMOTE_INTERFACE_VERSION"

struct ISteamMusicRemote
{
	const void *vtbl;
};

struct ISteamMusicRemote *SteamMusicRemote_generic(const char *version);
void SteamMusicRemote_set_version(const char *version);
extern struct ISteamMusicRemote *SteamMusicRemote(void);

#endif /* ISTEAMMUSICREMOTE_H */
