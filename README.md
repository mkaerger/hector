hector
======

A tokenizer for credit cards written in C++.
hector is called via socket, data is stored in a postgres database.

Documentation
-------------

For documentation, see:

    doc/

[Read the documentation](https://github.com/mkaerger/hector/blob/master/doc/README.md)


Build Instructions
------------------

You'll need the `Boost <http://www.boost.org>` libraries installed somewhere.

On Debian systems, the following packages are required:

- libboost-regex-dev

To build the library the following commands should be issued::

    $ make

Linux requires the following dependencies installed:
- libpg5
- libpg-dev
- g++


Credits
-------

Visit [PostgreSQL](http://www.postgresql.org/)!

