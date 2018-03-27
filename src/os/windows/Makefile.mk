SUBDIRS-y :=
EXTDIRS-y :=

libos_windows := libos_windows$(STATIC_LIB_EXT)

STATICLIBS-y := $(libos_windows)

objs := \
	windows.c.o

CFLAGS-y += -fPIC -fvisibility=hidden -I../..

OBJS-$(libos_windows)-y := $(objs)
