Transition Actions
=============================

A transition action can be used to control drawing during a sequence of actions.
Viewer applications should normally suspend drawing when such a sequence begins
and resume drawing when it ends. If a transition action is present during a
sequence, the viewer should render the state of the page viewing area as it
exists after completion of the previous action and display it using a transition
specified in the action dictionary. Once this transition completes, drawing
should be suspended again.

.. c:autodoc:: libzathura/actions/action-transition.h
