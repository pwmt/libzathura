# See LICENSE file for license and copyright information

include ../config.mk
include ../common.mk

include config.mk

PROJECT = tests
SOURCE  = $(wildcard *.c)
OBJECTS = ${SOURCE:.c=.o}

all: ${PROJECT}

run: ${PROJECT}
	$(QUIET)./${PROJECT}

%.o: %.c
	$(ECHO) CC $<
	@mkdir -p .depend/$(dir $@)
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $< -MMD -MF .depend/$@.dep

${PROJECT}: options ${OBJECTS}
	${QUIET}${MAKE} -C ..
	$(ECHO) CC -o $@
	$(QUIET)${CC} ${SFLAGS} ${LDFLAGS} -o $@ ${OBJECTS} ${LIBS}

${OBJECTS}: ../config.mk

valgrind: ${PROJECT}
	 $(QUIET)${VALGRIND} ${VALGRIND_ARGUMENTS} ./${PROJECT}

clean:
	$(QUIET)rm -rf ${PROJECT} ${OBJECTS} .depend ${PROJECT}.info

.PHONY: all options clean debug run

-include $(wildcard .depend/*.dep)
