SUBDIRS-y :=
EXTDIRS-y :=

libsteamhttp := libsteamhttp$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamhttp)

objs := \
	ISteamHTTP.c.o \
	ISteamHTTP001.c.o \
	ISteamHTTP002.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamhttp)-y := $(objs)
