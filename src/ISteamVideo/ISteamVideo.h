#ifndef ISTEAMVIDEO_H
#define ISTEAMVIDEO_H 1

#define STEAMVIDEO_INTERFACE_VERSION_PREFIX "STEAMVIDEO_INTERFACE_V"

struct ISteamVideo
{
	union
	{
		const void *ptr;
		const struct ISteamVideo001Vtbl *v001;
		const struct ISteamVideo002Vtbl *v002;
	} vtbl;
};

struct ISteamVideo *SteamVideo_generic(const char *version);
void SteamVideo_set_version(const char *version);
extern struct ISteamVideo *SteamVideo(void);

#endif /* ISTEAMVIDEO_H */
