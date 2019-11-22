SUBDIRS-y :=
EXTDIRS-y :=

libsteammatchmakingservers := libsteammatchmakingservers$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteammatchmakingservers)

objs := \
	ISteamMatchmakingServers.c.o \
	ISteamMatchmakingServers001.c.o \
	ISteamMatchmakingServers002.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteammatchmakingservers)-y := $(objs)
