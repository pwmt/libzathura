Installation
============

Dependencies
------------

The core of libzathura depends on `glib <http://gnome.org>`_. In addition we
require some libraries for testing and building the documentation. You can find
a full list of the dependencies here:

* `glib <http://gnome.org>`_ >= 2.32.4
* `check <http://check.sorceforge.net>`_ >= 0.9.8
* `libfiu <http://blitiri.com.ar/p/libfiu>`_ >= 0.91
* `python-docutils <http://docutils.sourceforge.net>`_
* `python-sphinx <http://sphinx-doc.org>`_

Stable version
--------------

.. note::

  There has not been a release from libzathura yet.

Since libzathura packages are available for many distributions it is recommended
to use them by installing them with your prefered package manager. Otherwise you
can grab the latest version of the source code from our website and build it by
hand

.. code-block:: sh

  tar xfv libzathura-<version>.tar.gz
  cd libzathura-<version>
  make
  make install

Developer version
-----------------

If you are interested in testing the very latest versions with all its new
features, that we are working on, type in the following commands:

.. code-block:: sh

  git clone git://pwmt.org/libzathura.git
  cd libzathura
  git checkout --track -b develop origin/develop
  make
  make install

For the installation of a file type plugin check the :plugins:(../plugins) section.
