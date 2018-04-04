SUBDIRS-y :=
EXTDIRS-y :=

libsteamhtmlsurface := libsteamhtmlsurface$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamhtmlsurface)

objs := \
	ISteamHTMLSurface.c.o \
	ISteamHTMLSurface002.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamhtmlsurface)-y := $(objs)
