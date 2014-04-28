# See LICENSE file for license and copyright information

include ../config.mk
include ../colors.mk
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
	$(call colorecho,CC,$<)
	@mkdir -p .depend/$(dir $(abspath $@))
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $< -MMD -MF .depend/$@.dep

%.do: %.c
	@mkdir -p .depend/$(dir $(abspath $@))
	$(call colorecho,CC,$<)
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} ${DFLAGS} -o $@ $< -MMD -MF .depend/$(abspath $@).dep

${PROJECT}: options ${OBJECTS}
	$(QUIET)${MAKE} WITH_LIBFIU=1 -C ..
	$(QUIET)${MAKE} -C plugin
	$(call colorecho,CC,$@)
	$(QUIET)${CC} ${SFLAGS} ${LDFLAGS} -o $@ ${OBJECTS} ${LIBS}

${PROJECT}-debug: options ${DOBJECTS}
	$(QUIET)${MAKE} WITH_LIBFIU=1 -C .. debug
	$(QUIET)${MAKE} -C plugin
	$(call colorecho,CC,$@)
	$(QUIET)${CC} ${LDFLAGS} -o ${PROJECT} ${DOBJECTS} ${LIBS}

../libzathura/version.h:
	$(MAKE) -C .. libzathura/version.h

${OBJECTS}: ../config.mk ../libzathura/version.h
${DOBJECTS}: ../config.mk ../libzathura/version.h

valgrind: ${PROJECT}
	 $(QUIET)${VALGRIND} ${VALGRIND_ARGUMENTS} ./${PROJECT}

clean:
	$(call colorecho,RM, "Clean test files")
	$(QUIET)rm -rf ${PROJECT}
	$(QUIET)rm -rf ${PROJECT}-debug
	$(QUIET)rm -rf ${OBJECTS}
	$(QUIET)rm -rf ${DOBJECTS}
	$(QUIET)rm -rf ${PROJECT}.info
	$(QUIET)rm -rf ${GCDA}
	$(QUIET)rm -rf ${GCNO}
	$(QUIET)rm -rf .depend

	$(QUIET)${MAKE} -C plugin clean

.PHONY: all options clean debug run

-include $(wildcard .depend/*.dep)
