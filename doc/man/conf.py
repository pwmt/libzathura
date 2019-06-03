# -*- coding: utf-8 -*-
#
# See LICENSE file for license and copyright information

import os

# -- General configuration ------------------------------------------------

extensions     = ['hawkmoth']
source_suffix  = '.rst'
master_doc     = 'libzathura.3'
templates_path = ['_templates']

# -- Project configuration ------------------------------------------------

project   = 'libzathura'
copyright = '2014-2019, pwmt.org'
version   = '0.0.1'
release   = '0.0.1'

# -- Options for manual page output ---------------------------------------

man_pages = [
    ('libzathura.3', 'libzathura', 'a document library', ['pwmt.org'], 3)
]

# -- Options for hawkmoth -------------------------------------------------

cautodoc_root = os.path.abspath('../../')
cautodoc_compat = 'javadoc-basic'
cautodoc_clang = "-DWITH_CAIRO"
