# See LICENSE file for license and copyright information

LIBZATHURA_VERSION_MAJOR = 0
LIBZATHURA_VERSION_MINOR = 0
LIBZATHURA_VERSION_REV   = 1

VERSION = ${LIBZATHURA_VERSION_MAJOR}.${LIBZATHURA_VERSION_MINOR}.${LIBZATHURA_VERSION_REV}

# If the API changes, the API version and the ABI version have to be bumped.
LIBZATHURA_VERSION_API = 1

# If the ABI breaks for any reason, this has to be bumped.
LIBZATHURA_VERSION_ABI = 1

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

# libs
GLIB_INC ?= $(shell pkg-config --cflags glib-2.0)
GLIB_LIB ?= $(shell pkg-config --libs glib-2.0)

GTK_INC ?= $(shell pkg-config --cflags gtk+-2.0)
GTK_LIB ?= $(shell pkg-config --libs gtk+-2.0)

GMODULE_INC ?= $(shell pkg-config --cflags gmodule-no-export-2.0)
GMODULE_LIB ?= $(shell pkg-config --libs gmodule-no-export-2.0)

FIU_INC ?= $(shell pkg-config --cflags libfiu)
FIU_LIB ?= $(shell pkg-config --libs libfiu)

INCS = ${GLIB_INC} ${GMODULE_INC} ${GTK_INC}
LIBS = ${GLIB_LIB} ${GMODULE_LIB} ${GTK_LIB} -lm

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

# libfiu
WITH_LIBFIU ?= 1
FIU_RUN ?= fiu-run -x

# set to something != 0 if you want verbose build output
VERBOSE ?= 0
