SUBDIRS-y :=
EXTDIRS-y :=

libsteamgameserver := libsteamgameserver$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamgameserver)

objs := \
	ISteamGameServer.c.o \
	ISteamGameServer011.c.o \
	ISteamGameServer012.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteamgameserver)-y := $(objs)
