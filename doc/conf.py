#!/usr/bin/env python2
# -*- coding: utf-8 -*-
# See LICENSE file for license and copyright information

import sys

extensions = [
    'sphinx.ext.intersphinx',
    'sphinx.ext.todo',
    'sphinx.ext.pngmath',
    'sphinx.ext.ifconfig',
    'breathe'
]

templates_path = ['_templates']

source_suffix = '.rst'

source_encoding = 'utf-8-sig'

master_doc = 'index'

project = 'libzathura'
copyright = '2014, pwmt.org'

version = '0.0.1'
release = '0.0.1'

exclude_patterns = ['_build']

pygments_style = 'sphinx'

# html
html_theme = 'sphinx_rtd_theme'
html_theme_path = ['_themes']
html_static_path = ['_static']
htmlhelp_basename = 'libzathuradoc'

# breathe
breathe_projects = {
    "libzathura": "./doxygen/xml"
}

breathe_projects_source = {
    "libzathura": "../libzathura"
}

breathe_default_project = "libzathura"

breathe_domain_by_extension = {
    "h": "c",
}
