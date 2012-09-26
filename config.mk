# See LICENSE file for license and copyright information

LIBZATHURA_VERSION_MAJOR = 0
LIBZATHURA_VERSION_MINOR = 0
LIBZATHURA_VERSION_REV   = 1

VERSION = ${LIBZATHURA_VERSION_MAJOR}.${LIBZATHURA_VERSION_MINOR}.${LIBZATHURA_VERSION_REV}

# Rules for the SOMAJOR and SOMINOR.
# Before a release check perform the following checks against the last release:
# * If a function has been removed or the paramaters of a function have changed
#   bump SOMAJOR and set SOMINOR to 0.
# * If any of the exported datastructures have changed in a incompatible way
# 	bump SOMAJOR and set SOMINOR to 0.
# * If a function has been added bump SOMINOR.

SOMAJOR = 1
SOMINOR = 0
SOVERSION = ${SOMAJOR}.${SOMINOR}

# paths
PREFIX ?= /usr
LIBDIR ?= ${PREFIX}/lib
INCLUDEDIR ?= ${PREFIX}/include

# girara
GIRARA_MIN_VERSION = 0.1.4
GIRARA_VERSION_CHECK ?= $(shell pkg-config --atleast-version=$(GIRARA_MIN_VERSION) girara-gtk2; echo $$?)

# libs
GIRARA_INC ?= $(shell pkg-config --cflags girara-gtk2)
GIRARA_LIB ?= $(shell pkg-config --libs girara-gtk2)

INCS = ${GIRARA_INC}
LIBS = ${GIRARA_LIB} -lm

# flags
CFLAGS += -std=c99 -pedantic -Wall -Wextra -fPIC $(INCS)

# linker flags
LDFLAGS += -fPIC

# debug
DFLAGS = -O0 -g

# compiler
CC ?= gcc

# strip
SFLAGS ?= -s

# set to something != 0 if you want verbose build output
VERBOSE ?= 0
