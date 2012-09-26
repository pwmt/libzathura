# See LICENSE file for license and copyright information

CHECK_INC ?= $(shell pkg-config --cflags check)
CHECK_LIB ?= $(shell pkg-config --libs check)

INCS += ${CHECK_INC}
LIBS += ${CHECK_LIB} ../libzathura.a
