SUBDIRS-y :=
EXTDIRS-y :=

libsteamuserstats := libsteamuserstats$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamuserstats)

objs := \
	ISteamUserStats.c.o \
	ISteamUserStats011.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteamuserstats)-y := $(objs)
