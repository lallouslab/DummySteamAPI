SUBDIRS-y :=
EXTDIRS-y :=

libsteamuser := libsteamuser$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamuser)

objs := \
	ISteamUser.c.o \
	ISteamUser004.c.o \
	ISteamUser016.c.o \
	ISteamUser017.c.o \
	ISteamUser018.c.o \
	ISteamUser019.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamuser)-y := $(objs)
