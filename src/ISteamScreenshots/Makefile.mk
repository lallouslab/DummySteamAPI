SUBDIRS-y :=
EXTDIRS-y :=

libsteamscreenshots := libsteamscreenshots$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamscreenshots)

objs := \
	ISteamScreenshots.c.o \
	ISteamScreenshots001.c.o \
	ISteamScreenshots002.c.o \
	ISteamScreenshots003.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamscreenshots)-y := $(objs)
