SUBDIRS-y :=
EXTDIRS-y :=

libsteamapplist := libsteamapplist$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamapplist)

objs := \
	ISteamAppList.c.o \
	ISteamAppList001.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteamapplist)-y := $(objs)
