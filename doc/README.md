Tokenizer service
-----------------
Starting the tokenizer service:
    $ bin/hector


Available Services
--------
- set_token_by_pan
- get_pan_by_token
- get_token_six_four_by_token
- get_provider_by_pan
- get_provider_by_token
- get_card_type_by_token
- get_card_type_by_pan
- get_tokens_by_token_six_four
- get_count_tokens_by_token_six_four


Client
------
Starting the console client:
    $ bin/hector_cli


Console client usage
--------------
    bin# ./hector_cli 
    ENTER SERVICE:
    >set_token_by_pan|1232-4434-2345-1123
    123244NWLRBB1123    


The web client
--------------
hector comes with a web interface written in PHP. Copy the files in phpstuff to your webserver directory:

    cp phpstuff/* localhost/hector


See the interface here: http://localhost/hector/ (depends on your webserver setup)


Postgres support
----------------
HOWTO set up a postgres database on linux. After installing the database from binary follow these instructions:

    # Add user if not exists
    adduser postgres

    # Set permissions to user postgres
    chown -R postgres:postgres /var/www/pgsql/

    # Become user postgres
    su - postgres

    # Go to pgsl directory (mine is located in /var/www/pgsql)
    cd /var/www/pgsql

    # Create data directory and start server
    bin/initdb -D ./data

    # Start server
    postgres@HC:/var/www/pgsql$ bin/pg_ctl -D ./data -l data/logfile start
    # Server status
    postgres@HC:/var/www/pgsql$ bin/pg_ctl -D ./data -l data/logfile status

    # Maybe create a postgres user
    bin/createuser 

    # Create a database
    bin/createdb --owner=postgres pcidss

    # Connect to the database
    cd bin/
    ./psql pcidss

    # Run sql scripts to set up your database
    pcidss=# \i plpgsql/create.sql 

    # Install pgcrypto extension
    cd /usr/local/src/postgresql-9.3.5/contrib/pgcrypto
