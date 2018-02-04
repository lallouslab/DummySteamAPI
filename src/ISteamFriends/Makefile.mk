SUBDIRS-y :=
EXTDIRS-y :=

libsteamfriends := libsteamfriends$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamfriends)

objs := \
	ISteamFriends.c.o \
	ISteamFriends001.c.o \
	ISteamFriends014.c.o \
	ISteamFriends015.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I..

OBJS-$(libsteamfriends)-y := $(objs)
