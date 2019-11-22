SUBDIRS-y :=
EXTDIRS-y :=

libsteamnetworking := libsteamnetworking$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamnetworking)

objs := \
	ISteamNetworking.c.o \
	ISteamNetworking001.c.o \
	ISteamNetworking005.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteamnetworking)-y := $(objs)
