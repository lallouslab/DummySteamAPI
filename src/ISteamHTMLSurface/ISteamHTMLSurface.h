#ifndef ISTEAMHTMLSURFACE_H
#define ISTEAMHTMLSURFACE_H 1

#define STEAMHTMLSURFACE_INTERFACE_VERSION_PREFIX "STEAMHTMLSURFACE_INTERFACE_VERSION_"

struct ISteamHTMLSurface
{
	union
	{
		const void *ptr;
		const struct ISteamHTMLSurface002Vtbl *v002;
		const struct ISteamHTMLSurface003Vtbl *v003;
	} vtbl;
};

struct ISteamHTMLSurface *SteamHTMLSurface_generic(const char *version);
void SteamHTMLSurface_set_version(const char *version);
extern struct ISteamHTMLSurface *SteamHTMLSurface(void);

#endif /* ISTEAMHTMLSURFACE_H */
