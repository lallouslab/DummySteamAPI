SUBDIRS-y :=
EXTDIRS-y :=

libsteamclient := libsteamclient$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamclient)

objs := \
	ISteamClient.c.o \
	ISteamClient006.c.o \
	ISteamClient012.c.o \
	ISteamClient014.c.o \
	ISteamClient016.c.o \
	ISteamClient017.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamclient)-y := $(objs)
