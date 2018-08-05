SUBDIRS-y :=
EXTDIRS-y :=

libsteamutils := libsteamutils$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamutils)

objs := \
	ISteamUtils.c.o \
	ISteamUtils001.c.o \
	ISteamUtils002.c.o \
	ISteamUtils006.c.o \
	ISteamUtils007.c.o \
	ISteamUtils008.c.o \
	ISteamUtils009.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamutils)-y := $(objs)
