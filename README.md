nulocks-core
============

nulocks - NUmerical bLOCKS is a modular and customizable clone of 2048 game in C++. This is a repository with core engine of the game.

The main purpose of Nulocks is to provide an engine of a game similar to original 2048 and an option to visualize it in any interface you want to implement it in. This repository contains this very engine that can be used to implement 2048 and/or use extended Nulocks possibilities such as determined by user size of the board and ending level of block in any user interface you want.

If you want to contribute, start with the documentation at: http://www.phitherek.mooo.com/doxy/nulocks-core/. I would be happy to see Nulocks implemented for many platforms in many graphical libraries.

Installation
------------

> make

> sudo make install

Make macros: LIBPREFIX - determines a directory in which the shared library should be placed, default: /usr/lib, INCLUDEPREFIX - determines a directory in which the header files should be placed, default: /usr/include. Use them with the install command.

Usage
-----

In your program include the main header file:

> \#include "nulocks-core/Board.h"

Compile your program with:

> g++ -o your_executable your_source.cpp -lnulockscore

Changelog
---------

* v. 0.1 - Initial version of the engine.
* v. 0.2 - Slightly changed game logic to reflect more of 2048 game' s logic.
* v. 0.2.1 - Makefile should generate library version 0.2 and not 0.1 (naming error resolved). Added uninstall action to Makefile.
