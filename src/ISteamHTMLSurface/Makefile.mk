SUBDIRS-y :=
EXTDIRS-y :=

libsteamhtmlsurface := libsteamhtmlsurface$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamhtmlsurface)

objs := \
	ISteamHTMLSurface.c.o \
	ISteamHTMLSurface002.c.o \
	ISteamHTMLSurface003.c.o \
	ISteamHTMLSurface004.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteamhtmlsurface)-y := $(objs)
