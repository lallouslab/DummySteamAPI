SUBDIRS-y :=
EXTDIRS-y :=

libos_linux := libos_linux$(STATIC_LIB_EXT)

STATICLIBS-y := $(libos_linux)

objs := \
	dl_override.c.o \
	linux.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I$(MKS_PROJDIR)/src

OBJS-$(libos_linux)-y := $(objs)
