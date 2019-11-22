SUBDIRS-y := $(OS)
EXTDIRS-y :=

libos := libos$(STATIC_LIB_EXT)

STATICLIBS-y := $(libos)

libs := \
	$(OS)/libos_$(OS)$(STATIC_LIB_EXT)

objs :=

CFLAGS-y += -fPIC -fvisibility=hidden

LIBS-$(libos)-y := $(libs)
OBJS-$(libos)-y := $(objs)
