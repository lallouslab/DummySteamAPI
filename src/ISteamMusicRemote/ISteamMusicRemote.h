#ifndef ISTEAMMUSICREMOTE_H
#define ISTEAMMUSICREMOTE_H 1

#define STEAMMUSICREMOTE_INTERFACE_VERSION_PREFIX "STEAMMUSICREMOTE_INTERFACE_VERSION"

struct ISteamMusicRemote
{
	union
	{
		const void *ptr;
		const struct ISteamMusicRemote001Vtbl *v001;
	} vtbl;
};

struct ISteamMusicRemote *SteamMusicRemote_generic(const char *version);
void SteamMusicRemote_set_version(const char *version);
extern struct ISteamMusicRemote *SteamMusicRemote(void);

#endif /* ISTEAMMUSICREMOTE_H */
