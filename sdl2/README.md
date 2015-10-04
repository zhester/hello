SDL2 Hello World
================

Depends on SDL2 development library.  The Makefile assumes `sdl2-config` is
available in the current path environment.

SDL2 on Debian
--------------

Installation via Debian software distribution:

    apt-get install libsdl2-dev

Building
--------

The Makefile is set to use Clang.  It should also work with gcc (untested).
I'll probably add a Visual Studio solution at a later date.

To build and test the example:

    make
    build/sdl2

This should draw a square-ish window with a dark blue gradient within the
application pane.

