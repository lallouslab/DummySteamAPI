SUBDIRS-y := \
	ISteamAppList \
	ISteamApps \
	ISteamClient \
	ISteamController \
	ISteamFriends \
	ISteamGameCoordinator \
	ISteamGameServer \
	ISteamGameServerStats \
	ISteamHTTP \
	ISteamMatchmaking \
	ISteamMatchmakingServers \
	ISteamMusic \
	ISteamMusicRemote \
	ISteamNetworking \
	ISteamRemoteStorage \
	ISteamScreenshots \
	ISteamUGC \
	ISteamUnifiedMessages \
	ISteamUser \
	ISteamUserStats \
	ISteamUtils \
	os
EXTDIRS-y :=

libsteam_api := ../bin/libsteam_api$(DYN_LIB_EXT)

BINS-y := $(libsteam_api)

libs := \
	ISteamAppList/libsteamapplist$(STATIC_LIB_EXT) \
	ISteamApps/libsteamapps$(STATIC_LIB_EXT) \
	ISteamClient/libsteamclient$(STATIC_LIB_EXT) \
	ISteamController/libsteamcontroller$(STATIC_LIB_EXT) \
	ISteamFriends/libsteamfriends$(STATIC_LIB_EXT) \
	ISteamGameCoordinator/libsteamgamecoordinator$(STATIC_LIB_EXT) \
	ISteamGameServer/libsteamgameserver$(STATIC_LIB_EXT) \
	ISteamGameServerStats/libsteamgameserverstats$(STATIC_LIB_EXT) \
	ISteamHTTP/libsteamhttp$(STATIC_LIB_EXT) \
	ISteamMatchmaking/libsteammatchmaking$(STATIC_LIB_EXT) \
	ISteamMatchmakingServers/libsteammatchmakingservers$(STATIC_LIB_EXT) \
	ISteamMusic/libsteammusic$(STATIC_LIB_EXT) \
	ISteamMusicRemote/libsteammusicremote$(STATIC_LIB_EXT) \
	ISteamNetworking/libsteamnetworking$(STATIC_LIB_EXT) \
	ISteamRemoteStorage/libsteamremotestorage$(STATIC_LIB_EXT) \
	ISteamScreenshots/libsteamscreenshots$(STATIC_LIB_EXT) \
	ISteamUGC/libsteamugc$(STATIC_LIB_EXT) \
	ISteamUnifiedMessages/libsteamunifiedmessages$(STATIC_LIB_EXT) \
	ISteamUser/libsteamuser$(STATIC_LIB_EXT) \
	ISteamUserStats/libsteamuserstats$(STATIC_LIB_EXT) \
	ISteamUtils/libsteamutils$(STATIC_LIB_EXT) \
	os/libos$(STATIC_LIB_EXT)

objs := \
	CCallback.c.o \
	callbacks.c.o \
	config.c.o \
	debug.c.o \
	dsa.c.o \
	setup_ifaces.c.o \
	steam_api.c.o \
	steam_gameserver.c.o \
	steamclient.c.o \
	utils.c.o

CFLAGS-y += -fPIC -I.
CFLAGS-$(CONFIG_OS_LINUX) += -pthread

LDFLAGS-$(libsteam_api)-y += $(LDFLAGS_SHARED) -Wl,--whole-archive $(libs) -Wl,--no-whole-archive
LDFLAGS-$(libsteam_api)-$(CONFIG_OS_LINUX) += -ldl -pthread
LDFLAGS-$(libsteam_api)-$(CONFIG_OS_WINDOWS) += -luserenv

DEPS-$(libsteam_api)-y := $(libs)
OBJS-$(libsteam_api)-y := $(objs)
