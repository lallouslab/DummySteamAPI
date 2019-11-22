SUBDIRS-y :=
EXTDIRS-y :=

libsteamgamecoordinator := libsteamgamecoordinator$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamgamecoordinator)

objs := \
	ISteamGameCoordinator.c.o \
	ISteamGameCoordinator001.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteamgamecoordinator)-y := $(objs)
