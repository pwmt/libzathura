# See LICENSE file for license and copyright information

include ../config.mk
include ../common.mk

include config.mk

PROJECT  = tests
SOURCE   = $(wildcard *.c)
OBJECTS  = ${SOURCE:.c=.o}
DOBJECTS = ${SOURCE:.c=.do}
GCDA     = ${SOURCE:.c=.gcda}
GCNO     = ${SOURCE:.c=.gcno}

ifneq (${WITH_LIBFIU},0)
FIU_EXEC += ${FIU_RUN}
endif

all: ${PROJECT}

debug: options ${PROJECT}-debug

run: ${PROJECT}
	$(QUIET)${FIU_EXEC} ./${PROJECT}

%.o: %.c
	$(ECHO) CC $<
	@mkdir -p .depend/$(dir $(abspath $@))
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $< -MMD -MF .depend/$@.dep

%.do: %.c
	@mkdir -p .depend/$(dir $(abspath $@))
	$(ECHO) CC $<
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} ${DFLAGS} -o $@ $< -MMD -MF .depend/$(abspath $@).dep

${PROJECT}: options ${OBJECTS}
	$(QUIET)${MAKE} WITH_LIBFIU=1 -C ..
	$(QUIET)${MAKE} -C plugin
	$(ECHO) CC -o $@
	$(QUIET)${CC} ${SFLAGS} ${LDFLAGS} -o $@ ${OBJECTS} ${LIBS}

${PROJECT}-debug: options ${DOBJECTS}
	$(QUIET)${MAKE} WITH_LIBFIU=1 -C .. debug
	$(QUIET)${MAKE} -C plugin
	$(ECHO) CC -o $@
	$(QUIET)${CC} ${LDFLAGS} -o ${PROJECT} ${DOBJECTS} ${LIBS}

../libzathura/version.h:
	$(MAKE) -C .. libzathura/version.h

${OBJECTS}: ../config.mk ../libzathura/version.h
${DOBJECTS}: ../config.mk ../libzathura/version.h

valgrind: ${PROJECT}
	 $(QUIET)${VALGRIND} ${VALGRIND_ARGUMENTS} ./${PROJECT}

clean:
	$(QUIET)${MAKE} -C plugin clean
	$(QUIET)rm -rf ${PROJECT} ${PROJECT}-debug ${OBJECTS} ${DOBJECTS} \
		.depend ${PROJECT}.info ${GCDA} ${GCNO}

.PHONY: all options clean debug run

-include $(wildcard .depend/*.dep)
