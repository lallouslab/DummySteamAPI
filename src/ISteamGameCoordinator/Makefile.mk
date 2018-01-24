SUBDIRS-y :=
EXTDIRS-y :=

libsteamgamecoordinator := libsteamgamecoordinator$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamgamecoordinator)

objs := \
	ISteamGameCoordinator.c.o \
	ISteamGameCoordinator001.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamgamecoordinator)-y := $(objs)
