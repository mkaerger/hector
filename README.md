hector
======

A tokenizer for credit cards written in C++.
hector is called via socket, data is stored in a postgres database.

Documentation
-------------

For documentation, see:

    doc/

[Read the documentation](https://github.com/mkaerger/hector/blob/master/doc/README.md)


Installation and compile-time options
-------------------------------------

You'll need the `Boost <http://www.boost.org>` libraries installed somewhere.


To install hector the following commands should be issued:

    $ aclocal && autoconf && autoheader && automake --add-missing

This will create a configure script.


It's your choice how to store your data. hector comes with two options:

    $ --enable-mongodb
    $ --enable-pgsql


Example:

    $ ./configure --prefix=/var/www/hector --enable-mongodb
    $ make
    $ make install

This will install hector in /var/www/, MongoDB support is enabled.



Credits
-------

Visit [PostgreSQL](http://www.postgresql.org/) and [mongoDB](http://docs.mongodb.org/ecosystem/drivers/cpp/)!
