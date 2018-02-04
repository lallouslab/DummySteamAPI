SUBDIRS-y :=
EXTDIRS-y :=

libsteamremotestorage := libsteamremotestorage$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamremotestorage)

objs := \
	ISteamRemoteStorage.c.o \
	ISteamRemoteStorage001.c.o \
	ISteamRemoteStorage012.c.o \
	ISteamRemoteStorage013.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamremotestorage)-y := $(objs)
