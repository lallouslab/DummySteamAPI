SUBDIRS-y :=
EXTDIRS-y :=

libsteamugc := libsteamugc$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamugc)

objs := \
	ISteamUGC.c.o \
	ISteamUGC001.c.o \
	ISteamUGC007.c.o \
	ISteamUGC010.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamugc)-y := $(objs)
