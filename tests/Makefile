# See LICENSE file for license and copyright information

include ../config.mk
include ../colors.mk
include ../common.mk

include config.mk

PROJECT       = tests
SOURCE        = $(wildcard *.c)
OBJECTS       = $(addprefix ${BUILDDIR_RELEASE}/,${SOURCE:.c=.o})
OBJECTS_DEBUG = $(addprefix ${BUILDDIR_DEBUG}/,${SOURCE:.c=.o})
OBJECTS_GCOV  = $(addprefix ${BUILDDIR_GCOV}/,${SOURCE:.c=.o})

ifneq (${WITH_MAGIC},0)
INCS += ${MAGIC_INC}
LIBS += ${MAGIC_LIB}
CPPFLAGS += -DWITH_MAGIC
endif

ifneq (${WITH_CAIRO},0)
INCS += ${CAIRO_INC}
LIBS += ${CAIRO_LIB}
CPPFLAGS += -DHAVE_CAIRO
endif

ifneq (${WITH_LIBFIU},0)
INCS += ${FIU_INC}
LIBS += ${FIU_LIB}
FIU_EXEC += ${FIU_RUN}
CPPFLAGS += -DFIU_ENABLE
endif

ifneq ($(wildcard ${VALGRIND_SUPPRESSION_FILE}),)
VALGRIND_ARGUMENTS += --suppressions=${VALGRIND_SUPPRESSION_FILE}
endif

all: options ${PROJECT}

options:
ifeq "$(VERBOSE)" "1"
	$(ECHO) ${PROJECT} build options:
	$(ECHO) "CFLAGS  = ${CFLAGS}"
	$(ECHO) "LDFLAGS = ${LDFLAGS}"
	$(ECHO) "DFLAGS  = ${DFLAGS}"
	$(ECHO) "CC      = ${CC}"
endif

# release

${PROJECT}: options ${OBJECTS}
	$(QUIET)${MAKE} WITH_LIBFIU=1 -C .. libzathura
	$(QUIET)${MAKE} -C plugin
	$(call colorecho,CC,$@)
	$(QUIET)${CC} ${SFLAGS} ${LDFLAGS} -o $@ \
		${OBJECTS} ${LIBZATHURA_RELEASE} ${LIBS}

${OBJECTS}: config.mk ../config.mk ../libzathura/version.h

${BUILDDIR_RELEASE}/%.o: %.c
	$(call colorecho,CC,$<)
	@mkdir -p ${DEPENDDIR}/$(dir $(abspath $@))
	@mkdir -p $(dir $(abspath $@))
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} \
		-o $@ $< -MMD -MF ${DEPENDDIR}/$(abspath $@).dep

run: ${PROJECT}
	$(QUIET)${FIU_EXEC} ./${PROJECT}

# debug

debug: options ${PROJECT}-debug

${PROJECT}-debug: ${OBJECTS_DEBUG}
	$(QUIET)${MAKE} WITH_LIBFIU=1 -C .. libzathura-debug
	$(QUIET)${MAKE} -C plugin
	$(call colorecho,CC,$@)
	$(QUIET)${CC} ${LDFLAGS} -o $@ \
		${OBJECTS_DEBUG} ${LIBZATHURA_DEBUG} ${LIBS}

${OBJECTS_DEBUG}: config.mk ../config.mk ../libzathura/version.h

${BUILDDIR_DEBUG}/%.o: %.c
	@mkdir -p ${DEPENDDIR}/$(dir $(abspath $@))
	@mkdir -p $(dir $(abspath $@))
	$(call colorecho,CC,$<)
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} ${DFLAGS} \
		-o $@ $< -MMD -MF ${DEPENDDIR}/$(abspath $@).dep

run-debug: ${PROJECT}-debug
	$(QUIET)${FIU_EXEC} ./${PROJECT}-debug

# gcov

gcov: options ${PROJECT}-gcov

${PROJECT}-gcov: options ${OBJECTS_GCOV}
	$(QUIET)${MAKE} WITH_LIBFIU=1 -C .. libzathura-gcov
	$(QUIET)${MAKE} -C plugin
	$(call colorecho,CC,$@)
	$(QUIET)${CC} ${LDFLAGS} ${GCOV_LDFLAGS} -o $@ \
		${OBJECTS_GCOV} ${LIBZATHURA_GCOV} ${LIBS}

${OBJECTS_GCOV}: config.mk ../config.mk ../libzathura/version.h

${BUILDDIR_GCOV}/%.o: %.c
	@mkdir -p ${DEPENDDIR}/$(dir $(abspath $@))
	@mkdir -p $(dir $(abspath $@))
	$(call colorecho,CC,$<)
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} ${GCOV_CFLAGS} ${DFLAGS} ${GCOV_DFLAGS} \
		-o $@ $< -MMD -MF ${DEPENDDIR}/$(abspath $@).dep

run-gcov: ${PROJECT}-gcov
	$(QUIET)${FIU_EXEC} ./${PROJECT}-gcov

../libzathura/version.h:
	$(MAKE) -C .. libzathura/version.h

valgrind: ${PROJECT}-debug
	 $(QUIET)G_SLICE=always-malloc G_DEBUG=gc-friendly ${FIU_EXEC} ${VALGRIND} ${VALGRIND_ARGUMENTS} ./${PROJECT}-debug

clean:
	$(call colorecho,RM, "Clean test files")
	$(QUIET)rm -rf ${PROJECT}
	$(QUIET)rm -rf ${PROJECT}-debug
	$(QUIET)rm -rf ${PROJECT}-gcov
	$(QUIET)rm -rf ${BUILDDIR}
	$(QUIET)rm -rf ${DEPENDDIR}

	$(QUIET)${MAKE} -C plugin clean

.PHONY: all options clean debug run

-include $(wildcard ${DEPENDDIR}/*.dep)
