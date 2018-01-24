SUBDIRS-y :=
EXTDIRS-y :=

libsteamgameserverstats := libsteamgameserverstats$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamgameserverstats)

objs := \
	ISteamGameServerStats.c.o \
	ISteamGameServerStats001.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamgameserverstats)-y := $(objs)
