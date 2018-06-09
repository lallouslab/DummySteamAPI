SUBDIRS-y :=
EXTDIRS-y :=

libsteaminventory := libsteaminventory$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteaminventory)

objs := \
	ISteamInventory.c.o \
	ISteamInventory001.c.o \
	ISteamInventory002.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteaminventory)-y := $(objs)
