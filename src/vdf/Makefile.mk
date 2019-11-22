SUBDIRS-y :=
EXTDIRS-y :=

libvdf := libvdf$(STATIC_LIB_EXT)

STATICLIBS-y := $(libvdf)

objs := vdf.c.o

CFLAGS-y += -fPIC -fvisibility=hidden

OBJS-$(libvdf)-y := $(objs)
