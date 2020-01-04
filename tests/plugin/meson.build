libzathura_plugin = library(
  'plugin',
  files('plugin.c'),
  dependencies: build_dependencies + [declare_dependency(link_with: libzathura)],
  include_directories: include_directories,
  c_args: defines + flags,
  name_prefix: ''
)
