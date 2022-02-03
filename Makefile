SHELL := /bin/bash

# If you move this project you can change the directory
# to match your GBDK root directory (ex: GBDK_HOME = "C:/GBDK/"
GBDK_HOME = ../../../gbdk/
LCC = $(GBDK_HOME)bin/lcc

# Set platforms to build here, spaced separated. (These are in the separate Makefile.targets)
# They can also be built/cleaned individually: "make gg" and "make gg-clean"
# Possible are: gb gbc pocket sms gg
#TARGETS=gb pocket sms gg
TARGETS=gb

# Configure platform specific LCC flags here:
LCCFLAGS_gb      = -Wl-yt0x19 -Wl-yo4 -Wm-yS -Wm-yn"$(PROJECTNAME)"
LCCFLAGS_pocket  = -Wl-yt0x19 -Wl-yo4 -Wm-yS -Wm-yn"$(PROJECTNAME)"
LCCFLAGS_sms     = -Wl-yo4 -Wm-yS
LCCFLAGS_gg      = -Wl-yo4 -Wm-yS

LCCFLAGS += $(LCCFLAGS_$(EXT)) -Wl-llib/$(PORT)/hUGEDriver.lib # This adds the current platform specific LCC Flags

LCCFLAGS += -Wl-j -autobank -Wb-ext=.rel -Wb-v # MBC + Autobanking related flags
# LCCFLAGS += -debug # Uncomment to enable debug output
# LCCFLAGS += -v     # Uncomment for lcc verbose output

CFLAGS = -Iinclude -Ires -Isrc/$(PORT) -Iobj/$(PLAT)

# You can set the name of the ROM file here
PROJECTNAME = libtest

# EXT?=gb # Only sets extension to default (game boy .gb) if not populated
SRCDIR      = src
SRCPLAT     = src/$(PORT)
OBJDIR      = obj/$(EXT)
RESDIR      = res
BINDIR      = build/$(EXT)
MKDIRS      = $(OBJDIR) $(BINDIR) # See bottom of Makefile for directory auto-creation

BINS	    = $(OBJDIR)/$(PROJECTNAME).$(EXT)
RSOURCES    = $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.vgm))) 
CSOURCES    = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(SRCPLAT),$(notdir $(wildcard $(dir)/*.c))) $(foreach dir,$(RESDIR),$(notdir $(wildcard $(dir)/*.c)))
ASMSOURCES  = $(foreach dir,$(SRCDIR),$(notdir $(wildcard $(dir)/*.s))) $(foreach dir,$(SRCPLAT),$(notdir $(wildcard $(dir)/*.s)))
OBJS        = $(CSOURCES:%.c=$(OBJDIR)/%.o) $(ASMSOURCES:%.s=$(OBJDIR)/%.o) $(RSOURCES:%.vgm=$(OBJDIR)/%.o)
RESOBJ      = $(RSOURCES:%.vgm=$(OBJDIR)/%.o)

DEPENDANT   = $(CSOURCES:%.c=$(OBJDIR)/%.o)

# Builds all targets sequentially
all: $(TARGETS)

# Dependencies
DEPS = $(DEPENDANT:%.o=%.d)

-include $(DEPS)

$(OBJDIR)/%.c:	$(RESDIR)/%.vgm
	python utils/vgm2data.py -v $< -o $@ -5 -w -3

$(OBJDIR)/%.o:	$(OBJDIR)/%.c
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .c files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(LCC) -Wf-MMD $(CFLAGS) -c -o $@ $<

# Compile .c files in "src/<target>/" to .o object files
$(OBJDIR)/%.o:	$(SRCPLAT)/%.c
	$(LCC) -Wf-MMD $(CFLAGS) -c -o $@ $<

# Compile .c files in "res/" to .o object files
$(OBJDIR)/%.o:	$(RESDIR)/%.c
	$(LCC) -Wf-MMD $(CFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/<target>/" to .o object files
$(OBJDIR)/%.o:	$(SRCPLAT)/%.s
	$(LCC) $(CFLAGS) -c -o $@ $<

# Compile .s assembly files in "src/" to .o object files
$(OBJDIR)/%.o:	$(SRCDIR)/%.s
	$(LCC) $(CFLAGS) -c -o $@ $<

# Link the compiled object files into a .gb ROM file
$(BINS):	$(RESOBJ) $(OBJS)
	$(LCC) $(LCCFLAGS) $(CFLAGS) -o $(BINDIR)/$(PROJECTNAME).$(EXT) $(OBJS)

clean:
	@echo Cleaning
	@for target in $(TARGETS); do \
		$(MAKE) $$target-clean; \
	done

# Include available build targets
include Makefile.targets


# create necessary directories after Makefile is parsed but before build
# info prevents the command from being pasted into the makefile
ifneq ($(strip $(EXT)),)           # Only make the directories if EXT has been set by a target
$(info $(shell mkdir -p $(MKDIRS)))
endif
