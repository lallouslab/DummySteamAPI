#ifndef ISTEAMINVENTORY_H
#define ISTEAMINVENTORY_H 1

#define STEAMINVENTORY_INTERFACE_VERSION_PREFIX "STEAMINVENTORY_INTERFACE_V"

struct ISteamInventory
{
	union
	{
		const void *ptr;
		const struct ISteamInventory001Vtbl *v001;
	} vtbl;
};

struct ISteamInventory *SteamInventory_generic(const char *version);
void SteamInventory_set_version(const char *version);
extern struct ISteamInventory *SteamInventory(void);

#endif /* ISTEAMINVENTORY_H */
