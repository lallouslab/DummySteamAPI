SUBDIRS-y :=
EXTDIRS-y :=

libos_linux := libos_linux$(STATIC_LIB_EXT)

STATICLIBS-y := $(libos_linux)

objs := \
	linux.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I../..

OBJS-$(libos_linux)-y := $(objs)
