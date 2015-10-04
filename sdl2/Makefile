##############################################################################
#
# Makefile
#
##############################################################################

# Basic compile environment settings
CC = /usr/bin/clang
CFLAGS = -Wall
LD = $(CC)
LDFLAGS = $(CFLAGS)
SHELL = /bin/sh

# Add debug symbols for any debug target.
debug: CFLAGS += -ggdb
debug: LDFLAGS += -ggdb

# Detect build environment.
UNAME := $(shell uname)

# Base name of the project and final binary
PROJ := $(shell basename `pwd`)

# SDL library
CFLAGS += $(shell sdl2-config --cflags)
LDFLAGS += $(shell sdl2-config --libs)

# Project source files
SOURCES := $(wildcard *.c)

# Build directory
BLDDIR = build

# Derive object targets from source files
OBJECTS := $(patsubst %.c, $(BLDDIR)/%.o, $(SOURCES))

# Default target
all: $(BLDDIR)/$(PROJ)

# How to build the project binary
$(BLDDIR)/$(PROJ): $(OBJECTS)
	$(LD) $(LDFLAGS) -o $@ $(OBJECTS)

# How to build object files
$(BLDDIR)/%.o: %.c | $(BLDDIR)
	$(CC) $(CFLAGS) -o $@ -c $<

# Make sure there's an output directory.
$(BLDDIR):
	mkdir -p $(BLDDIR)

# How to clean the output files
clean:
	rm -rf $(BLDDIR)

