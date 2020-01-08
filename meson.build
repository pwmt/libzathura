project('libzathura', 'c',
  version: '0.0.1',
  meson_version: '>=0.48',
  default_options: 'c_std=c11',
  license: 'zlib'
)

project_description = 'Document Library'
project_url = 'https://pwmt.org/projects/libzathura'

version = meson.project_version()
version_array = version.split('.')

# Rules for so_major and so_minor:
# Before a release perform the following checks against the last release:
# * If a function has been removed or the paramaters of a function have changed
#   bump SOMAJOR and set SOMINOR to 0.
# * If any of the exported datastructures have changed in a incompatible way
#   bump SOMAJOR and set SOMINOR to 0.
# * If a function has been added bump SOMINOR.
so_major = 1
so_minor = 1
so_version = '@0@.@1@'.format(so_major, so_minor)

conf_data = configuration_data()
conf_data.set('ZVMAJOR', version_array[0])
conf_data.set('ZVMINOR', version_array[1])
conf_data.set('ZVREV',   version_array[2])
conf_data.set('ZVAPI',   so_major)
conf_data.set('ZVABI',   so_minor)
conf_data.set('version',  version)

cc = meson.get_compiler('c')

prefix = get_option('prefix')
localedir = get_option('localedir')

# required dependencies
libm = cc.find_library('m', required: false)
glib = dependency('glib-2.0', version: '>=2.32.4')
gio = dependency('gio-unix-2.0', required: host_machine.system() != 'windows')
gmodule = dependency('gmodule-no-export-2.0', version: '>=2.50')

build_dependencies = [libm, glib, gio, gmodule]
pc_requires = ['glib-2.0']

# defines
defines = [
  '-DGETTEXT_PACKAGE="libzathura-@0@"'.format(so_major),
  '-DLOCALEDIR="@0@"'.format(join_paths(prefix, localedir)),
  '-D_DEFAULT_SOURCE',
]

# compile flags
flags = [
  '-Wall',
  '-Wextra',
  '-pedantic',
  '-Wmissing-declarations',
  '-Werror=implicit-function-declaration',
  '-Werror=vla',
]

if cc.get_id() == 'clang'
  flags += '-Wno-unused-command-line-argument'
endif

flags = cc.get_supported_arguments(flags)

# optional dependencies
cairo = dependency('cairo', required: get_option('enable-cairo'))
magic = cc.find_library('magic', required: get_option('enable-magic')) #fixme
libfiu = dependency('libfiu', version: '>=0.91', required: get_option('enable-libfiu'))

if magic.found()
  build_dependencies += magic
  defines += '-DWITH_MAGIC'
endif

if cairo.found()
  build_dependencies += cairo
  defines += '-DHAVE_CAIRO'
endif

if get_option('enable-libfiu') and libfiu.found()
  build_dependencies += libfiu
  defines += '-DWITH_LIBFIU'
endif

# generate version header file
version_header = configure_file(
  input: 'libzathura/version.h.in',
  output: 'version.h',
  configuration: conf_data
)

include_directories = [
  include_directories('.')
]

# source files
sources = files(
  'libzathura/action.c',
  'libzathura/actions/action-goto-3d-view.c',
  'libzathura/actions/action-goto-embedded.c',
  'libzathura/actions/action-goto-remote.c',
  'libzathura/actions/action-goto.c',
  'libzathura/actions/action-hide-annotations.c',
  'libzathura/actions/action-launch.c',
  'libzathura/actions/action-movie.c',
  'libzathura/actions/action-named.c',
  'libzathura/actions/action-rendition.c',
  'libzathura/actions/action-set-ocg-state.c',
  'libzathura/actions/action-sound.c',
  'libzathura/actions/action-thread.c',
  'libzathura/actions/action-transition.c',
  'libzathura/actions/action-uri.c',
  'libzathura/annotations.c',
  'libzathura/annotations/annotation-3d.c',
  'libzathura/annotations/annotation-caret.c',
  'libzathura/annotations/annotation-file-attachment.c',
  'libzathura/annotations/annotation-free-text.c',
  'libzathura/annotations/annotation-highlight.c',
  'libzathura/annotations/annotation-ink.c',
  'libzathura/annotations/annotation-line.c',
  'libzathura/annotations/annotation-link.c',
  'libzathura/annotations/annotation-markup.c',
  'libzathura/annotations/annotation-movie.c',
  'libzathura/annotations/annotation-polygon.c',
  'libzathura/annotations/annotation-polyline.c',
  'libzathura/annotations/annotation-popup.c',
  'libzathura/annotations/annotation-printer-mark.c',
  'libzathura/annotations/annotation-screen.c',
  'libzathura/annotations/annotation-sound.c',
  'libzathura/annotations/annotation-square-and-circle.c',
  'libzathura/annotations/annotation-squiggly.c',
  'libzathura/annotations/annotation-stamp.c',
  'libzathura/annotations/annotation-strike-out.c',
  'libzathura/annotations/annotation-text.c',
  'libzathura/annotations/annotation-underline.c',
  'libzathura/annotations/annotation-widget.c',
  'libzathura/annotations/border.c',
  'libzathura/annotations/internal/annotation-text-markup.c',
  'libzathura/attachment.c',
  'libzathura/checked-integer-arithmetic.c',
  'libzathura/document.c',
  'libzathura/form-fields.c',
  'libzathura/form-fields/form-field-button.c',
  'libzathura/form-fields/form-field-choice.c',
  'libzathura/form-fields/form-field-signature.c',
  'libzathura/form-fields/form-field-text.c',
  'libzathura/image-buffer.c',
  'libzathura/image.c',
  'libzathura/internal.c',
  'libzathura/metadata.c',
  'libzathura/options.c',
  'libzathura/outline.c',
  'libzathura/page.c',
  'libzathura/plugin-api.c',
  'libzathura/plugin-manager.c',
  'libzathura/plugin.c',
  'libzathura/transition.c'
)

# header files to install
headers = {
  'libzathura': files(
    'libzathura/action.h',
    'libzathura/annotations.h',
    'libzathura/attachment.h',
    'libzathura/checked-integer-arithmetic.h',
    'libzathura/document.h',
    'libzathura/error.h',
    'libzathura/fiu-local.h',
    'libzathura/form-fields.h',
    'libzathura/image-buffer.h',
    'libzathura/image.h',
    'libzathura/internal.h',
    'libzathura/libzathura.h',
    'libzathura/list.h',
    'libzathura/macros.h',
    'libzathura/metadata.h',
    'libzathura/movie.h',
    'libzathura/node.h',
    'libzathura/options.h',
    'libzathura/outline.h',
    'libzathura/page.h',
    'libzathura/plugin-api.h',
    'libzathura/plugin-manager.h',
    'libzathura/plugin.h',
    'libzathura/sound.h',
    'libzathura/transition.h',
    'libzathura/types.h',
  ),
  'libzathura/actions': files(
    'libzathura/actions/action-goto-3d-view.h',
    'libzathura/actions/action-goto-embedded.h',
    'libzathura/actions/action-goto-remote.h',
    'libzathura/actions/action-goto.h',
    'libzathura/actions/action-hide-annotations.h',
    'libzathura/actions/action-launch.h',
    'libzathura/actions/action-movie.h',
    'libzathura/actions/action-named.h',
    'libzathura/actions/action-rendition.h',
    'libzathura/actions/action-set-ocg-state.h',
    'libzathura/actions/action-sound.h',
    'libzathura/actions/action-thread.h',
    'libzathura/actions/action-transition.h',
    'libzathura/actions/action-uri.h',
    'libzathura/actions/internal.h'
  ),
  'libzathura/actions/internal': files(
    'libzathura/actions/internal/action-goto-3d-view.h',
    'libzathura/actions/internal/action-goto-embedded.h',
    'libzathura/actions/internal/action-goto-remote.h',
    'libzathura/actions/internal/action-goto.h',
    'libzathura/actions/internal/action-hide-annotations.h',
    'libzathura/actions/internal/action-launch.h',
    'libzathura/actions/internal/action-movie.h',
    'libzathura/actions/internal/action-named.h',
    'libzathura/actions/internal/action-rendition.h',
    'libzathura/actions/internal/action-set-ocg-state.h',
    'libzathura/actions/internal/action-sound.h',
    'libzathura/actions/internal/action-thread.h',
    'libzathura/actions/internal/action-transition.h',
    'libzathura/actions/internal/action-uri.h'
  ),
  'libzathura/annotations': files(
    'libzathura/annotations/annotation-3d.h',
    'libzathura/annotations/annotation-caret.h',
    'libzathura/annotations/annotation-circle.h',
    'libzathura/annotations/annotation-file-attachment.h',
    'libzathura/annotations/annotation-free-text.h',
    'libzathura/annotations/annotation-highlight.h',
    'libzathura/annotations/annotation-ink.h',
    'libzathura/annotations/annotation-line.h',
    'libzathura/annotations/annotation-link.h',
    'libzathura/annotations/annotation-markup.h',
    'libzathura/annotations/annotation-movie.h',
    'libzathura/annotations/annotation-polygon.h',
    'libzathura/annotations/annotation-polyline.h',
    'libzathura/annotations/annotation-popup.h',
    'libzathura/annotations/annotation-printer-mark.h',
    'libzathura/annotations/annotation-screen.h',
    'libzathura/annotations/annotation-sound.h',
    'libzathura/annotations/annotation-square.h',
    'libzathura/annotations/annotation-squiggly.h',
    'libzathura/annotations/annotation-stamp.h',
    'libzathura/annotations/annotation-strike-out.h',
    'libzathura/annotations/annotation-text.h',
    'libzathura/annotations/annotation-trap-net.h',
    'libzathura/annotations/annotation-underline.h',
    'libzathura/annotations/annotation-watermark.h',
    'libzathura/annotations/annotation-widget.h',
    'libzathura/annotations/border.h',
    'libzathura/annotations/color.h',
    'libzathura/annotations/flags.h',
    'libzathura/annotations/internal.h',
    'libzathura/annotations/types.h'
  ),
  'libzathura/annotations/internal': files(
    'libzathura/annotations/internal/annotation-3d.h',
    'libzathura/annotations/internal/annotation-caret.h',
    'libzathura/annotations/internal/annotation-file.h',
    'libzathura/annotations/internal/annotation-free-text.h',
    'libzathura/annotations/internal/annotation-ink.h',
    'libzathura/annotations/internal/annotation-line.h',
    'libzathura/annotations/internal/annotation-link.h',
    'libzathura/annotations/internal/annotation-markup.h',
    'libzathura/annotations/internal/annotation-movie.h',
    'libzathura/annotations/internal/annotation-polygon.h',
    'libzathura/annotations/internal/annotation-polyline.h',
    'libzathura/annotations/internal/annotation-popup.h',
    'libzathura/annotations/internal/annotation-printer-mark.h',
    'libzathura/annotations/internal/annotation-screen.h',
    'libzathura/annotations/internal/annotation-sound.h',
    'libzathura/annotations/internal/annotation-square-and-circle.h',
    'libzathura/annotations/internal/annotation-stamp.h',
    'libzathura/annotations/internal/annotation-text-markup.h',
    'libzathura/annotations/internal/annotation-text.h',
    'libzathura/annotations/internal/annotation-widget.h',
  ),
  'libzathura/crypto': files(
    'libzathura/crypto/certificate.h',
    'libzathura/crypto/private-key.h',
    'libzathura/crypto/signature.h'
  ),
  'libzathura/form-fields': files(
    'libzathura/form-fields/form-field-button.h',
    'libzathura/form-fields/form-field-choice.h',
    'libzathura/form-fields/form-field-signature.h',
    'libzathura/form-fields/form-field-text.h',
    'libzathura/form-fields/internal.h',
  ),
  'libzathura/form-fields/internal': files(
    'libzathura/form-fields/internal/form-field-button.h',
    'libzathura/form-fields/internal/form-field-choice.h',
    'libzathura/form-fields/internal/form-field-signature.h',
    'libzathura/form-fields/internal/form-field-text.h',
  ),
  'libzathura/plugin-api': files(
    'libzathura/plugin-api/action.h',
    'libzathura/plugin-api/annotations.h',
    'libzathura/plugin-api/attachment.h',
    'libzathura/plugin-api/document.h',
    'libzathura/plugin-api/form-fields.h',
    'libzathura/plugin-api/image-buffer.h',
    'libzathura/plugin-api/image.h',
    'libzathura/plugin-api/metadata.h',
    'libzathura/plugin-api/outline.h',
    'libzathura/plugin-api/page.h',
    'libzathura/plugin-api/transition.h'
  ),
  'libzathura/plugin-api/actions': files(
    'libzathura/plugin-api/actions/action-goto-3d-view.h',
    'libzathura/plugin-api/actions/action-goto-embedded.h',
    'libzathura/plugin-api/actions/action-goto-remote.h',
    'libzathura/plugin-api/actions/action-goto.h',
    'libzathura/plugin-api/actions/action-hide-annotations.h',
    'libzathura/plugin-api/actions/action-launch.h',
    'libzathura/plugin-api/actions/action-movie.h',
    'libzathura/plugin-api/actions/action-named.h',
    'libzathura/plugin-api/actions/action-rendition.h',
    'libzathura/plugin-api/actions/action-set-ocg-state.h',
    'libzathura/plugin-api/actions/action-sound.h',
    'libzathura/plugin-api/actions/action-thread.h',
    'libzathura/plugin-api/actions/action-transition.h',
    'libzathura/plugin-api/actions/action-uri.h'
  ),
  'libzathura/plugin-api/form-fields': files(
    'libzathura/plugin-api/form-fields/form-field-button.h',
    'libzathura/plugin-api/form-fields/form-field-choice-item.h',
    'libzathura/plugin-api/form-fields/form-field-choice.h',
    'libzathura/plugin-api/form-fields/form-field-signature.h',
    'libzathura/plugin-api/form-fields/form-field-text.h'
  )
}

# libzathura library
libzathura = library(
  'zathura',
  sources,
  dependencies: build_dependencies,
  version: so_version,
  install: true,
  include_directories: include_directories,
  c_args: defines + flags,
  # gnu_symbol_visibility: 'hidden'
)

libzathura_dependency = declare_dependency(link_with: libzathura, include_directories: include_directories)

install_headers(version_header, subdir: 'libzathura')
foreach path, header_files: headers
  install_headers(header_files, subdir: path)
endforeach

# pkg-config file
pkg = import('pkgconfig')
pkg.generate(
  name: meson.project_name(),
  description: project_description,
  url: project_url,
  version: version,
  libraries: libzathura,
  requires: pc_requires
)

subdir('doc')
subdir('tests')
