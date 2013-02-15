# See LICENSE file for license and copyright information

include config.mk
include common.mk

PROJECT   = libzathura
SOURCE    = $(wildcard ${PROJECT}/*.c)
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
	@mkdir -p .depend/$(dir $(abspath $@))
	$(ECHO) CC $<
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $< -MMD -MF .depend/$(abspath $@).dep

%.do: %.c
	@mkdir -p .depend/$(dir $(abspath $@))
	$(ECHO) CC $<
	$(QUIET)${CC} -c ${CPPFLAGS} ${CFLAGS} ${DFLAGS} -o $@ $< -MMD -MF .depend/$(abspath $@).dep

${OBJECTS}:  config.mk ${PROJECT}/version.h
${DOBJECTS}: config.mk ${PROJECT}/version.h

${PROJECT}: ${PROJECT}/version.h static shared

static: ${PROJECT}.a
shared: ${PROJECT}.so.${SOVERSION}

${PROJECT}.a: ${OBJECTS}
	$(QUIET)rm -f ${PROJECT}.a
	$(ECHO) AR rcs $@
	$(QUIET)ar rcs $@ ${OBJECTS}

${PROJECT}.so.${SOVERSION}: ${OBJECTS}
	$(ECHO) LD $@
	$(QUIET)${CC} -Wl,-soname,${PROJECT}.so.${SOMAJOR} -shared ${LDFLAGS} -o $@ ${OBJECTS} ${LIBS}

clean:
	$(QUIET)rm -rf ${OBJECTS} ${PROJECT}-${VERSION}.tar.gz gcov \
		${DOBJECTS} ${PROJECT}.a ${PROJECT}-debug.a ${PROJECT}.pc doc \
		$(PROJECT).so.${SOVERSION} ${PROJECT}-debug.so.${SOVERSION} .depend \
		${PROJECT}-${VERSION}.tar.gz ${PROJECT}/version.h ${GCDA} ${GCNO} $(PROJECT).info
	$(QUIET)${MAKE} -C tests clean

${PROJECT}-debug: ${PROJECT}-debug.a ${PROJECT}-debug.so.${SOVERSION}

${PROJECT}-debug.a: ${DOBJECTS}
	$(QUIET)rm -f ${PROJECT}.a
	$(ECHO) AR rcs ${PROJECT}.a
	$(QUIET)ar rc ${PROJECT}.a ${DOBJECTS}

${PROJECT}-debug.so.${SOVERSION}: ${DOBJECTS}
	$(ECHO) LD ${PROJECT}.so.${SOMAJOR}
	$(QUIET)${CC} -Wl,-soname,${PROJECT}.so.${SOMAJOR} -shared ${LDFLAGS} \
		-o ${PROJECT}.so.${SOVERSION} ${DOBJECTS} ${LIBS}

debug: options ${PROJECT}-debug

doc:
	$(QUIET)doxygen Doxyfile

test: ${PROJECT}
	$(QUIET)${MAKE} -C tests run

gcov: clean
	$(QUIET)env CFLAGS="-fprofile-arcs -ftest-coverage" LDFLAGS="-fprofile-arcs" WITH_LIBFIU=1 ${MAKE} debug
	$(QUIET)env CFLAGS="-fprofile-arcs -ftest-coverage" LDFLAGS="-fprofile-arcs" ${MAKE} test
	$(QUIET)lcov --base-directory . --directory ${PROJECT} --capture --output-file $(PROJECT).info
	$(QUIET)genhtml --output-directory gcov $(PROJECT).info

${PROJECT}.pc: ${PROJECTNV}.pc.in config.mk
	$(QUIET)echo project=${PROJECT} > ${PROJECT}.pc
	$(QUIET)echo version=${VERSION} >> ${PROJECT}.pc
	$(QUIET)echo includedir=${INCLUDEDIR} >> ${PROJECT}.pc
	$(QUIET)echo libdir=${LIBDIR} >> ${PROJECT}.pc
	$(QUIET)cat ${PROJECTNV}.pc.in >> ${PROJECT}.pc

install-static: static
	$(ECHO) installing static library
	$(QUIET)mkdir -m 755 -p ${DESTDIR}${LIBDIR}
	$(QUIET)install -m 644 ${PROJECT}.a ${DESTDIR}${LIBDIR}

install-shared: shared
	$(ECHO) installing shared library
	$(QUIET)mkdir -m 755 -p ${DESTDIR}${LIBDIR}
	$(QUIET)install -m 644 ${PROJECT}.so.${SOVERSION} ${DESTDIR}${LIBDIR}
	$(QUIET)ln -s ${PROJECT}.so.${SOVERSION} ${DESTDIR}${LIBDIR}/${PROJECT}.so.${SOMAJOR} || \
		echo "Failed to create ${PROJECT}.so.${SOMAJOR}. Please check if it exists and points to the correct version of ${PROJECT}.so."
	$(QUIET)ln -s ${PROJECT}.so.${SOVERSION} ${DESTDIR}${LIBDIR}/${PROJECT}.so || \
		echo "Failed to create ${PROJECT}.so. Please check if it exists and points to the correct version of ${PROJECT}.so."

install: options install-static install-shared install-headers
		$(QUIET)${MAKE} -C po install

install-headers: ${PROJECT}/version.h ${PROJECT}.pc
	$(ECHO) installing pkgconfig file
	$(QUIET)mkdir -m 755 -p ${DESTDIR}${LIBDIR}/pkgconfig
	$(QUIET)install -m 644 ${PROJECT}.pc ${DESTDIR}${LIBDIR}/pkgconfig
	$(ECHO) installing header files
	$(QUIET)mkdir -m 755 -p ${DESTDIR}${INCLUDEDIR}/zathura
	$(QUIET)install -m 644 ${HEADERS_INSTALL} ${DESTDIR}${INCLUDEDIR}/zathura

uninstall: uninstall-headers
	$(ECHO) removing library file
	$(QUIET)rm -f ${LIBDIR}/${PROJECT}.a ${LIBDIR}/${PROJECT}.so.${SOVERSION} \
		${LIBDIR}/${PROJECT}.so.${SOMAJOR} ${LIBDIR}/${PROJECT}.so
	$(QUIET)${MAKE} -C po uninstall

uninstall-headers:
	$(ECHO) removing header files
	$(QUIET)rm -rf ${INCLUDEDIR}/zathura
	$(ECHO) removing pkgconfig file
	$(QUIET)rm -f ${LIBDIR}/pkgconfig/${PROJECT}.pc

.PHONY: all options clean debug doc test dist install install-headers \
	uninstall ninstall-headers ${PROJECT} ${PROJECT}-debug static shared \
	install-static install-shared

TDEPENDS = ${OBJECTS:.o=.o.dep}
DEPENDS = ${TDEPENDS:^=.depend/}
-include ${DEPENDS}
