Actions
=======

Instead of simply jumping to a destination in the document, an annotation or
outline item can specify an action for the viewer application to perform, such
as launching an application, playing a sound, or changing an annotation's
appearance state.

Action Types
------------

.. toctree::
  :maxdepth: 2
  :numbered:

  actions/action-goto.rst
  actions/action-goto-remote.rst
  actions/action-goto-embedded.rst
  actions/action-launch.rst
  actions/action-thread.rst
  actions/action-uri.rst
  actions/action-sound.rst
  actions/action-movie.rst
  actions/action-hide-annotations.rst
  actions/action-named.rst
  actions/action-set-ocg-state.rst
  actions/action-rendition.rst
  actions/action-transition.rst
  actions/action-goto-3d-view.rst

Common action
-------------

.. doxygenfile:: libzathura/action.h
  :project: libzathura
