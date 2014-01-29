# See LICENSE file for license and copyright information

include ../common.mk
include ../config.mk

include config.mk

ALLSPHINXOPTS = -d $(BUILDDIR)/doctrees $(SPHINXOPTS) .

all: html 

clean:
	$(QUIET)make -C doxygen clean
	$(QUIET)rm -rf $(BUILDDIR)

html:
	$(QUIET)make -C . doxygen
	$(QUIET)$(SPHINXBUILD) -b html $(ALLSPHINXOPTS) $(BUILDDIR)/html
