SUBDIRS-y :=
EXTDIRS-y :=

libsteamcontroller := libsteamcontroller$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamcontroller)

objs := \
	ISteamController.c.o \
	ISteamController001.c.o \
	ISteamController003.c.o \
	ISteamController005.c.o \
	ISteamController006.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamcontroller)-y := $(objs)
