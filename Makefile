# See LICENSE file for license and copyright information

include config.mk
include colors.mk
include common.mk

PROJECT   = libzathura
SOURCE    = $(wildcard ${PROJECT}/*.c ${PROJECT}/**/*.c)
OBJECTS   = ${SOURCE:.c=.o}
DOBJECTS  = ${SOURCE:.c=.do}
GCDA  		= ${SOURCE:.c=.gcda}
GCNO 			= ${SOURCE:.c=.gcno}
HEADERS   = $(filter-out ${PROJECT}/version.h, $(filter-out ${PROJECT/}internal.h, $(wildcard *.h)))
HEADERS_INSTALL = ${HEADERS} ${PROJECT}/version.h

ifneq (${WITH_LIBFIU},0)
INCS += ${FIU_INC}
LIBS += ${FIU_LIB}
CFLAGS += "-DFIU_ENABLE"
endif

all: options ${PROJECT}

options:
	@echo ${PROJECT} build options:
	@echo "CFLAGS  = ${CFLAGS}"
	@echo "LDFLAGS = ${LDFLAGS}"
	@echo "DFLAGS  = ${DFLAGS}"
	@echo "CC      = ${CC}"

${PROJECT}/version.h: ${PROJECT}/version.h.in config.mk
	$(QUIET)sed 's/ZVMAJOR/${LIBZATHURA_VERSION_MAJOR}/' < ${PROJECT}/version.h.in | \
		sed 's/ZVMINOR/${LIBZATHURA_VERSION_MINOR}/' | \
		sed 's/ZVREV/${LIBZATHURA_VERSION_REV}/' | \
		sed 's/ZVAPI/${LIBZATHURA_VERSION_API}/' | \
		sed 's/ZVABI/${LIBZATHURA_VERSION_ABI}/' > ${PROJECT}/version.h

%.o: %.c
	$(call colorecho,CC,$<)
	@mkdir -p .depend/$(dir $(abspath $@))
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $< -MMD -MF .depend/$(abspath $@).dep

%.do: %.c
	$(call colorecho,CC,$<)
	@mkdir -p .depend/$(dir $(abspath $@))
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} ${DFLAGS} -o $@ $< -MMD -MF .depend/$(abspath $@).dep

${OBJECTS}:  config.mk ${PROJECT}/version.h
${DOBJECTS}: config.mk ${PROJECT}/version.h

${PROJECT}: ${PROJECT}/version.h static shared

static: ${PROJECT}.a
shared: ${PROJECT}.so.${SOVERSION}

${PROJECT}.a: ${OBJECTS}
	$(QUIET)rm -f ${PROJECT}.a
	$(call colorecho,AR,$@)
	$(QUIET)ar rcs $@ ${OBJECTS}

${PROJECT}.so.${SOVERSION}: ${OBJECTS}
	$(call colorecho,LD,$@)
	$(QUIET)${CC} -Wl,-soname,${PROJECT}.so.${SOMAJOR} -shared ${LDFLAGS} -o $@ ${OBJECTS} ${LIBS}

clean:
	$(call colorecho,RM, "Clean objects and builds")
	$(QUIET)rm -rf ${OBJECTS}
	$(QUIET)rm -rf ${PROJECT}.a
	$(QUIET)rm -rf ${PROJECT}.so

	$(call colorecho,RM, "Clean debug objects and builds")
	$(QUIET)rm -rf ${DOBJECTS}
	$(QUIET)rm -rf ${PROJECT}-debug.a
	$(QUIET)rm -rf ${PROJECT}-debug.so

	$(call colorecho,RM, "Clean pkg-config files")
	$(QUIET)rm -rf ${PROJECT}.pc

	$(call colorecho,RM, "Clean dependencies")
	$(QUIET)rm -rf .depend

	$(call colorecho,RM, "Clean distributionfiles")
	$(QUIET)rm -rf ${PROJECT}-${VERSION}.tar.gz
	$(QUIET)rm -rf ${PROJECT}.info
	$(QUIET)rm -rf ${PROJECT}/version.h

	$(call colorecho,RM, "Clean code analysis")
	$(QUIET)rm -rf gcov
	$(QUIET)rm -rf ${GCDA}
	$(QUIET)rm -rf ${GCNO}

	$(QUIET)${MAKE} -C tests clean
	$(QUIET)${MAKE} -C doc clean

${PROJECT}-debug: ${PROJECT}-debug.a ${PROJECT}-debug.so.${SOVERSION}

${PROJECT}-debug.a: ${DOBJECTS}
	$(QUIET)rm -f ${PROJECT}.a
	$(call colorecho,AR,${PROJECT}.a)
	$(QUIET)ar rc ${PROJECT}.a ${DOBJECTS}

${PROJECT}-debug.so.${SOVERSION}: ${DOBJECTS}
	$(call colorecho,LD,${PROJECT}.so.${SOMAJOR})
	$(QUIET)${CC} -Wl,-soname,${PROJECT}.so.${SOMAJOR} -shared ${LDFLAGS} \
		-o ${PROJECT}.so.${SOVERSION} ${DOBJECTS} ${LIBS}

debug: options ${PROJECT}-debug

doc:
	$(QUIET)${MAKE} -C doc

test: ${PROJECT}
	$(QUIET)${MAKE} -C tests run

gcov: clean
	$(QUIET)env CFLAGS="-fprofile-arcs -ftest-coverage" LDFLAGS="-fprofile-arcs" WITH_LIBFIU=1 ${MAKE} debug
	$(QUIET)env CFLAGS="-fprofile-arcs -ftest-coverage" LDFLAGS="-fprofile-arcs" ${MAKE} test
	$(call colorecho,LCOV,"Analyse data")
	$(QUIET)lcov --base-directory . --directory ${PROJECT} --capture --output-file $(PROJECT).info
	$(call colorecho,LCOV,"Generate report")
	$(QUIET)genhtml --output-directory gcov $(PROJECT).info

${PROJECT}.pc: ${PROJECTNV}.pc.in config.mk
	$(QUIET)echo project=${PROJECT} > ${PROJECT}.pc
	$(QUIET)echo version=${VERSION} >> ${PROJECT}.pc
	$(QUIET)echo includedir=${INCLUDEDIR} >> ${PROJECT}.pc
	$(QUIET)echo libdir=${LIBDIR} >> ${PROJECT}.pc
	$(QUIET)cat ${PROJECTNV}.pc.in >> ${PROJECT}.pc

install-static: static
	$(call colorecho,INSTALL,"Install static library")
	$(QUIET)mkdir -m 755 -p ${DESTDIR}${LIBDIR}
	$(QUIET)install -m 644 ${PROJECT}.a ${DESTDIR}${LIBDIR}

install-shared: shared
	$(call colorecho,INSTALL,"Install shared library")
	$(QUIET)mkdir -m 755 -p ${DESTDIR}${LIBDIR}
	$(QUIET)install -m 644 ${PROJECT}.so.${SOVERSION} ${DESTDIR}${LIBDIR}
	$(QUIET)ln -s ${PROJECT}.so.${SOVERSION} ${DESTDIR}${LIBDIR}/${PROJECT}.so.${SOMAJOR} || \
		echo "Failed to create ${PROJECT}.so.${SOMAJOR}. Please check if it exists and points to the correct version of ${PROJECT}.so."
	$(QUIET)ln -s ${PROJECT}.so.${SOVERSION} ${DESTDIR}${LIBDIR}/${PROJECT}.so || \
		echo "Failed to create ${PROJECT}.so. Please check if it exists and points to the correct version of ${PROJECT}.so."

install: options install-static install-shared install-headers
		$(QUIET)${MAKE} -C po install

install-headers: ${PROJECT}/version.h ${PROJECT}.pc
	$(call colorecho,INSTALL,"Install pkg-config file")
	$(QUIET)mkdir -m 755 -p ${DESTDIR}${LIBDIR}/pkgconfig
	$(QUIET)install -m 644 ${PROJECT}.pc ${DESTDIR}${LIBDIR}/pkgconfig
	$(call colorecho,INSTALL,"Install header files")
	$(QUIET)mkdir -m 755 -p ${DESTDIR}${INCLUDEDIR}/zathura
	$(QUIET)install -m 644 ${HEADERS_INSTALL} ${DESTDIR}${INCLUDEDIR}/zathura

uninstall: uninstall-headers
	$(call colorecho,UNINSTALL,"Remove library files")
	$(QUIET)rm -f ${LIBDIR}/${PROJECT}.a ${LIBDIR}/${PROJECT}.so.${SOVERSION} \
		${LIBDIR}/${PROJECT}.so.${SOMAJOR} ${LIBDIR}/${PROJECT}.so
	$(QUIET)${MAKE} -C po uninstall

uninstall-headers:
	$(call colorecho,UNINSTALL,"Remove header files")
	$(QUIET)rm -rf ${INCLUDEDIR}/zathura
	$(call colorecho,UNINSTALL,"Remove pkg-config file")
	$(QUIET)rm -f ${LIBDIR}/pkgconfig/${PROJECT}.pc

.PHONY: all options clean debug doc test dist install install-headers \
	uninstall ninstall-headers ${PROJECT} ${PROJECT}-debug static shared \
	install-static install-shared

TDEPENDS = ${OBJECTS:.o=.o.dep}
DEPENDS = ${TDEPENDS:^=.depend/}
-include ${DEPENDS}
