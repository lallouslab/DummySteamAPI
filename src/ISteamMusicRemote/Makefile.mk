SUBDIRS-y :=
EXTDIRS-y :=

libsteammusicremote := libsteammusicremote$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteammusicremote)

objs := \
	ISteamMusicRemote.c.o \
	ISteamMusicRemote001.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteammusicremote)-y := $(objs)
