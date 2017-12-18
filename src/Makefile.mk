SUBDIRS-y :=
EXTDIRS-y :=

libsteam_api := ../bin/libsteam_api$(DYN_LIB_EXT)

BINS-y := $(libsteam_api)

objs := \
	steam_api.c.o \
	isteamapps.c.o \
	isteamfriends.c.o \
	isteamuserstats.c.o

CFLAGS-y += -fPIC
LDFLAGS-$(libsteam_api)-y += $(LDFLAGS_SHARED)

OBJS-$(libsteam_api)-y := $(objs)
