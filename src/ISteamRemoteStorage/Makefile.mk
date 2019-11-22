SUBDIRS-y :=
EXTDIRS-y :=

libsteamremotestorage := libsteamremotestorage$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamremotestorage)

objs := \
	ISteamRemoteStorage.c.o \
	ISteamRemoteStorage001.c.o \
	ISteamRemoteStorage012.c.o \
	ISteamRemoteStorage013.c.o \
	ISteamRemoteStorage014.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteamremotestorage)-y := $(objs)
