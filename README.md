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


To build the library the following commands should be issued:

    $ aclocal && autoconf && autoheader && automake --add-missing

It's your choice how to store your data. hector comes with two options:

    $ --enable-mongodb
    $ --enable-pgsql

Example:

    $ ./configure --prefix=/var/www/hector --enable-mongodb

This will install hector in /var/www/, MongoDB support is anabled.



Credits
-------

Visit [PostgreSQL](http://www.postgresql.org/) and [mongoDB](http://docs.mongodb.org/ecosystem/drivers/cpp/)!
