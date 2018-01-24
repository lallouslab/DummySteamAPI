SUBDIRS-y :=
EXTDIRS-y :=

libsteamunifiedmessages := libsteamunifiedmessages$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamunifiedmessages)

objs := \
	ISteamUnifiedMessages.c.o \
	ISteamUnifiedMessages001.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamunifiedmessages)-y := $(objs)
