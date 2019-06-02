sphinx = find_program('sphinx-build')

if sphinx.found()
  custom_target('html',
    command: [
      sphinx,
      '-b', 'html',
      '-D', 'version=' + version,
      '-D', 'release=' + version,
      meson.current_source_dir(),
      meson.current_build_dir()],
    output: ['index.html'],
    input: [
      'conf.py',
    ],
    build_by_default: true,
    install: false,
  )

  custom_target('man pages',
    command: [
      sphinx,
      '-b', 'man',
      '-D', 'version=' + version,
      '-D', 'release=' + version,
      join_paths(meson.current_source_dir(), 'man'),
      meson.current_build_dir()],
    output: ['libzathura.3'],
    input: [
      'man/conf.py',
    ],
    build_by_default: true,
    install: true,
    install_dir: [
      join_paths(get_option('mandir'), 'man3'),
    ]
  )
endif
