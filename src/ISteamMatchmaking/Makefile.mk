SUBDIRS-y :=
EXTDIRS-y :=

libsteammatchmaking := libsteammatchmaking$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteammatchmaking)

objs := \
	ISteamMatchmaking.c.o \
	ISteamMatchmaking001.c.o \
	ISteamMatchmaking009.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteammatchmaking)-y := $(objs)
