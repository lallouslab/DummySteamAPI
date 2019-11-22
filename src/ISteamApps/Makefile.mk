SUBDIRS-y :=
EXTDIRS-y :=

libsteamapps := libsteamapps$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamapps)

objs := \
	ISteamApps.c.o \
	ISteamApps001.c.o \
	ISteamApps003.c.o \
	ISteamApps005.c.o \
	ISteamApps006.c.o \
	ISteamApps007.c.o \
	ISteamApps008.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteamapps)-y := $(objs)
