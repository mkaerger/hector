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


# Run test
cd /var/www/hector_mysql/bin/ && ./hector &>/dev/null &
sleep 4
/var/www/hector_mysql/bin/./hector_test 1111-2222-3333-4444
killall -9 hector

cd /var/www/hector_pgsql/bin/ && ./hector &>/dev/null &
sleep 4
/var/www/hector_pgsql/bin/./hector_test 1111-2222-3333-4444
killall -9 hector

cd /var/www/hector_mongodb/bin/ && ./hector &>/dev/null &
sleep 4
/var/www/hector_mongodb/bin/./hector_test 1111-2222-3333-4444
killall -9 hector

cd /var/www/hector_elasticsearch/bin/ && ./hector &>/dev/null &
sleep 4
/var/www/hector_elasticsearch/bin/./hector_test 1111-2222-3333-4444
killall -9 hector
