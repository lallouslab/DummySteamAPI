SUBDIRS-y :=
EXTDIRS-y :=

libsteamparentalsettings := libsteamparentalsettings$(STATIC_LIB_EXT)

STATICLIBS-y := $(libsteamparentalsettings)

objs := \
	ISteamParentalSettings.c.o \
	ISteamParentalSettings001.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libsteamparentalsettings)-y := $(objs)
