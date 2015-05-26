#!/bin/bash


cd /var/www/hector_pgsql/bin/ && ./hector &>/dev/null &
sleep 4
/var/www/hector_pgsql/bin/./hector_test 5928-4320-6407-0589 
killall -9 hector


cd /var/www/hector_mysql/bin/ && ./hector &>/dev/null &
sleep 4
/var/www/hector_mysql/bin/./hector_test 5928-4320-6407-0589 
killall -9 hector


cd /var/www/hector_mongodb/bin/ && ./hector &>/dev/null &
sleep 4
/var/www/hector_mongodb/bin/./hector_test 5928-4320-6407-0589 
killall -9 hector


cd /var/www/hector_elasticsearch/bin/ && ./hector &>/dev/null &
sleep 4
/var/www/hector_elasticsearch/bin/./hector_test 5928-4320-6407-0589 
killall -9 hector

