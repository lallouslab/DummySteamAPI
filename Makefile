MKS_PROJDIR := .
MKS_TOP_BUILDDIR := .
MKS := makesys

# MKS_PROJDIR :=
# MKS_TOP_BUILDDIR :=
# MKS :=

# Disable any builtin suffix rules
.SUFFIXES:
# Disable any builtin pattern rules
MAKEFLAGS += --no-builtin-rules

THIS := $(lastword $(MAKEFILE_LIST))

targets := all build clean defconfig install setup test

define mks_make
$(MAKE) -C $(MKS_TOP_BUILDDIR) -f $(MKS)/Makefile $1 MKS_PROJDIR=$(MKS_PROJDIR) MKS_TOP_BUILDDIR=$(MKS_TOP_BUILDDIR)
endef

.PHONY: $(targets) mks

$(targets): mks
	@true

mks: $(THIS)
	+$(call mks_make,$(MAKECMDGOALS))

$(THIS): $(MKS)/Makefile.stub
	+$(call mks_make,setup)
