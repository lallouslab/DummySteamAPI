#ifndef ISTEAMCONTROLLER_H
#define ISTEAMCONTROLLER_H 1

#define STEAMCONTROLLER_INTERFACE_VERSION_PREFIX0 "STEAMCONTROLLER_INTERFACE_VERSION"
#define STEAMCONTROLLER_INTERFACE_VERSION_PREFIX1 "SteamController"

struct ISteamControllerImpl;

struct ISteamControllerImpl *SteamController_generic(const char *version);
extern struct ISteamControllerImpl *SteamController(void);

#endif /* ISTEAMCONTROLLER_H */
