.. _plugins:

Plugins
=======

The structure of libzathura's plugin system is quite simple: A plugin-manager is
capable of loading plugins from a directory or directly from a file and then use
them to load a supported document from a given path. Each loaded plugin
registers itself by a name, its version, a special function as well as the
mimetypes it supports.

Each plugin has to implement a basic set of functionality so that it can be used
in a meaningful way with libzathura. For instance if a plugin is capable of
rendering a page, but not able to open a document structure at all, it has
really no use to libzathura. On the contrary the export of images out of the
document might not be considered as that important.

The plugin **must** contain the call to a specific macro that defines a certain
set of functions and expects several properties of the plugin as a parameter.
Those are called by the plugin-manager to register the plugin and are mandatory
for the plugin to work correctly.

.. toctree::

   plugin-manager
   plugin
   plugin-api
