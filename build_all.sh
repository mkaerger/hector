#!/bin/bash
# Helper script for development

# MYSQL
make clean && \
aclocal && autoconf && autoheader && automake --add-missing && \
./configure --prefix=/var/www/hector_mysql --enable-mysql && \
make && make install

# PGSQL
make clean && \
aclocal && autoconf && autoheader && automake --add-missing && \
./configure --prefix=/var/www/hector_pgsql --enable-pgsql && \
make && make install

# MONGODB
make clean && \
aclocal && autoconf && autoheader && automake --add-missing && \
./configure --prefix=/var/www/hector_mongodb --enable-mongodb && \
make && make install

# ELASTICSEARCH
make clean && \
aclocal && autoconf && autoheader && automake --add-missing && \
./configure --prefix=/var/www/hector_elasticsearch --enable-elasticsearch && \
make && make install
