# Enable delayed variable expansion
.SECONDEXPANSION:
# Disable any existing implicit rule
.SUFFIXES:

all: build

TOP := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
THIS := $(TOP)/Makefile
MKCONFIG := $(TOP)/Makefile.conf
TOP_BUILDDIR ?= $(CURDIR)
CACHEDIR := $(TOP)/makesys.cache
CUR_SUBDIR ?= /
LOCALCACHEDIR := $(CACHEDIR)$(CUR_SUBDIR)

empty :=

V ?=
V_ECHO_CMD   := @
V_SILENT_CMD := @
ifneq ("x$(V)","x")
  V_ECHO_CMD   := @true $(empty)
  V_SILENT_CMD :=
endif

ifneq ("x$(wildcard $(MKCONFIG))","x")
  include $(MKCONFIG)
else ifneq ("x$(word 1, $(MAKECMDGOALS))","xdefconfig")
  $(error Please run make defconfig)
endif

MAKEEXT := $(MAKE) TOP_BUILDDIR=$(TOP_BUILDDIR)
MAKETHIS := $(MAKE) -f $(THIS) TOP_BUILDDIR=$(TOP_BUILDDIR)

CCDEPS := $(CC) -MD -MP
HOSTCCDEPS := $(HOSTCC) -MD -MP
CPPDEPS := $(CPP) -MD -MP
HOSTCPPDEPS := $(HOSTCPP) -MD -MP
CXXDEPS := $(CXX) -MD -MP
HOSTCXXDEPS := $(HOSTCXX) -MD -MP

include Makefile.mk

BUILDEXTDIRS := $(EXTDIRS-y:%=build-%)
TESTEXTDIRS := $(EXTDIRS-y:%=test-%)
CLEANEXTDIRS := $(EXTDIRS-y:%=clean-%)

.PHONY: $(BUILDEXTDIRS)
.PHONY: $(TESTEXTDIRS)
.PHONY: $(CLEANEXTDIRS)

BUILDSUBDIRS := $(SUBDIRS-y:%=build-%)
TESTSUBDIRS := $(SUBDIRS-y:%=test-%)
CLEANSUBDIRS := $(SUBDIRS-y:%=clean-%)

.PHONY: $(BUILDSUBDIRS)
.PHONY: $(TESTSUBDIRS)
.PHONY: $(CLEANSUBDIRS)

OPTBUILDSUBDIRS := $(OPTSUBDIRS-y:%=build-%)
OPTTESTSUBDIRS := $(OPTSUBDIRS-y:%=test-%)
OPTCLEANSUBDIRS := $(OPTSUBDIRS-y:%=clean-%)

.PHONY: $(OPTBUILDSUBDIRS)
.PHONY: $(OPTTESTSUBDIRS)
.PHONY: $(OPTCLEANSUBDIRS)

.PHONY: build-all-TGT  clean-all-TGT
.PHONY: build-all-HOST clean-all-HOST
.PHONY: build-all-CUST clean-all-CUST
.PHONY: test-all-TEST  clean-all-TEST

.PHONY: all build build-all
.PHONY: test test-all
.PHONY: clean clean-all

defconfig:
	$(V_ECHO_CMD)echo " GEN             Makefile.conf"
	$(V_SILENT_CMD)cp $(MKCONFIG).sample $(MKCONFIG)

$(LOCALCACHEDIR):
	$(V_ECHO_CMD)echo " MKDIR           $(LOCALCACHEDIR)"
	$(V_SILENT_CMD)mkdir -p $(LOCALCACHEDIR)

build: $(LOCALCACHEDIR) $(BUILDEXTDIRS) $(BUILDSUBDIRS)
	+@$(MAKETHIS) --no-print-directory CUR_SUBDIR=$(CUR_SUBDIR) build-all
$(BUILDEXTDIRS)::
	+@$(MAKEEXT) -C $(@:build-%=%) build
$(BUILDSUBDIRS):: $(BUILDEXTDIRS)
	+@$(MAKETHIS) -C $(@:build-%=%) CUR_SUBDIR=$(CUR_SUBDIR)$(@:build-%=%)/ build
build-all: build-all-TGT build-all-HOST build-all-CUST

$(OPTBUILDSUBDIRS):
	+@$(MAKETHIS) -C $(@:build-%=%) CUR_SUBDIR=$(CUR_SUBDIR)$(@:build-%=%)/ build

test: build $(LOCALCACHEDIR) $(TESTEXTDIRS) $(TESTSUBDIRS)
	+@$(MAKETHIS) --no-print-directory CUR_SUBDIR=$(CUR_SUBDIR) test-all
$(TESTEXTDIRS)::
	+@$(MAKEEXT) -C $(@:test-%=%) test
$(TESTSUBDIRS):: $(TESTEXTDIRS)
	+@$(MAKETHIS) -C $(@:test-%=%) CUR_SUBDIR=$(CUR_SUBDIR)$(@:test-%=%)/ test
test-all: test-all-TEST

$(OPTTESTSUBDIRS):
	+@$(MAKETHIS) -C $(@:test-%=%) CUR_SUBDIR=$(CUR_SUBDIR)$(@:test-%=%)/ test

clean: $(CLEANEXTDIRS) $(CLEANSUBDIRS)
	+@$(MAKETHIS) --no-print-directory CUR_SUBDIR=$(CUR_SUBDIR) clean-all
$(CLEANEXTDIRS)::
	+@$(MAKEEXT) -C $(@:clean-%=%) clean
$(CLEANSUBDIRS):: $(CLEANEXTDIRS)
	+@$(MAKETHIS) -C $(@:clean-%=%) CUR_SUBDIR=$(CUR_SUBDIR)$(@:clean-%=%)/ clean
clean-all: clean-all-TGT clean-all-HOST clean-all-CUST clean-all-TEST

$(OPTCLEANSUBDIRS):
	+@$(MAKETHIS) -C $(@:clean-%=%) CUR_SUBDIR=$(CUR_SUBDIR)$(@:clean-%=%)/ clean

# Make all intermediate files persistent.
.SECONDARY:

ALL_TARGETS :=

include $(TOP)/mk/Makefile.tgt
include $(TOP)/mk/Makefile.host
include $(TOP)/mk/Makefile.cust
include $(TOP)/mk/Makefile.test

$(ALL_TARGETS): $(MKCONFIG) $(THIS) $(TOP)/mk/Makefile.tgt $(TOP)/mk/Makefile.host $(TOP)/mk/Makefile.cust $(TOP)/mk/Makefile.test $(CURDIR)/Makefile.mk
