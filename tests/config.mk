# See LICENSE file for license and copyright information

CHECK_INC ?= $(shell pkg-config --cflags check)
CHECK_LIB ?= $(shell pkg-config --libs check)

INCS += ${CHECK_INC} ${FIU_INC} -I ../libzathura
LIBS += ${CHECK_LIB} ${FIU_LIB} -Wl,--whole-archive -Wl,--no-whole-archive
LDFLAGS += -rdynamic

LIBZATHURA_RELEASE=../${BUILDDIR_RELEASE}/libzathura.a
LIBZATHURA_DEBUG=../${BUILDDIR_DEBUG}/libzathura.a
LIBZATHURA_GCOV=../${BUILDDIR_GCOV}/libzathura.a
