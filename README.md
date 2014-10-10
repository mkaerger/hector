hector
======

A tokenizer for credit cards written in C++.
hector is called via socket, it savely handles all your credit card data and provides functions to access them by tokens. hector returns a tokenized version of your credit card number and stores additional information like the corresponding bank by BIN list lookup.

Documentation
-------------

For documentation [read the documentation](https://github.com/mkaerger/hector/blob/master/doc/README.md)!


Installation and compile-time options
-------------------------------------

You'll need the `Boost <http://www.boost.org>` libraries installed somewhere.


To install hector the following commands should be issued:

    $ aclocal && autoconf && autoheader && automake --add-missing

This will create a configure script.


Example installation:

    $ ./configure --prefix=/var/www/hector --enable-mongodb
    $ make
    $ make install

This will install hector in /var/www/, MongoDB support is enabled.


It's your choice how to store your data. hector comes with three options:
    
    --enable-mongodb
    This tells hector to store all data in a MongoDB database	

    --enable-pgsql
    This tells hector to store all data in a PostgreSQL database	

    --enable-mysql
    This tells hector to store all data in a MySQL database	

Credits
-------

Visit [PostgreSQL](http://www.postgresql.org/), [mongoDB](http://docs.mongodb.org/ecosystem/drivers/cpp/) and [MySQL](http://mysql.com)!
