SUBDIRS-y :=
EXTDIRS-y :=

libsteamvideo := libsteamvideo$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamvideo)

objs := \
	ISteamVideo.c.o \
	ISteamVideo001.c.o \
	ISteamVideo002.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteamvideo)-y := $(objs)
