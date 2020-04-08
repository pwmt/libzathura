sphinx = find_program('sphinx-build')
pymod = import('python')
python = pymod.find_installation('python3')
python_required_modules = ['sphinx_rtd_theme', 'hawkmoth']

if sphinx.found()
	# Check required modules
	foreach p : python_required_modules
		script = 'import importlib.util; import sys; exit(1) if importlib.util.find_spec(\''+ p +'\') is None else exit(0)'
		if run_command(python, '-c', script).returncode() != 0
			error('Required Python module \'' + p + '\' not found')
		endif
	endforeach

  doc_sources = [
    'index.rst',
    'installation.rst',
    'usage/index.rst',
    'api/index.rst',
    'api/document.rst',
    'api/options.rst',
    'api/overview.rst',
    'api/plugin-manager.rst',
    'api/error.rst',
    'api/actions.rst',
    'api/actions/action-launch.rst',
    'api/actions/action-sound.rst',
    'api/actions/action-hide-annotations.rst',
    'api/actions/action-rendition.rst',
    'api/actions/action-goto-remote.rst',
    'api/actions/action-goto-embedded.rst',
    'api/actions/action-named.rst',
    'api/actions/action-set-ocg-state.rst',
    'api/actions/action-uri.rst',
    'api/actions/action-goto-3d-view.rst',
    'api/actions/action-movie.rst',
    'api/actions/action-transition.rst',
    'api/actions/action-thread.rst',
    'api/actions/action-goto.rst',
    'api/annotations.rst',
    'api/annotations/annotation-rubber-stamp.rst',
    'api/annotations/annotation-polygon-and-polyline.rst',
    'api/annotations/annotation-file-attachment.rst',
    'api/annotations/annotation-movie.rst',
    'api/annotations/annotation-popup.rst',
    'api/annotations/annotation-trap-network.rst',
    'api/annotations/annotation-text-markup.rst',
    'api/annotations/annotation-watermark.rst',
    'api/annotations/annotation-caret.rst',
    'api/annotations/annotation-markup.rst',
    'api/annotations/annotation-sound.rst',
    'api/annotations/annotation-line.rst',
    'api/annotations/annotation-link.rst',
    'api/annotations/annotation-text.rst',
    'api/annotations/annotation-printers-mark.rst',
    'api/annotations/annotation-square-and-circle.rst',
    'api/annotations/annotation-screen.rst',
    'api/annotations/annotation-ink.rst',
    'api/annotations/annotation-free-text.rst',
    'api/annotations/annotation-widget.rst',
    'api/form-fields.rst',
    'api/form-fields/form-field-button.rst',
    'api/form-fields/form-field-signature.rst',
    'api/form-fields/form-field-text.rst',
    'api/form-fields/form-field-choice.rst',
    'plugins/index.rst',
    'plugins/plugin-api.rst',
    'plugins/plugin-manager.rst',
    'plugins/plugin.rst',
    'development/index.rst',
    'development/contributing.rst',
  ]
  custom_target('html',
    command: [
      sphinx,
      '-b', 'html',
      '-D', 'version=' + version,
      '-D', 'release=' + version,
      meson.current_source_dir(),
      '@OUTDIR@/html'
    ],
    output: ['html'],
    input: [
      'conf.py',
    ] + doc_sources,
    build_by_default: false,
    install: false,
  )

  custom_target('man pages',
    command: [
      sphinx,
      '-b', 'man',
      '-D', 'version=' + version,
      '-D', 'release=' + version,
      join_paths(meson.current_source_dir(), 'man'),
      '@OUTDIR@/man'
    ],
    output: ['man'],
    input: [
      'man/conf.py',
      'man/libzathura.3.rst',
    ],
    build_by_default: false,
    install: true,
    install_dir: [
      join_paths(get_option('mandir'), 'man3'),
    ]
  )
endif
