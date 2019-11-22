SUBDIRS-y :=
EXTDIRS-y :=

libsteammusic := libsteammusic$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteammusic)

objs := \
	ISteamMusic.c.o \
	ISteamMusic001.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteammusic)-y := $(objs)
