hector
======

A tokenizer for credit cards written in C++.


Tokenizer service
-------
Starting the tokenizer service:
    $ bin/hector

Client
------
Starting the console client:
    s bin/hector_cli


Services
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


Console client usage
--------------

    bin# ./hector_cli 
    ENTER SERVICE:
    >set_token_by_pan|1232-4434-2345-1123
    e98474a6f496d67c3872f2862211355f9d9f3762584a183a1f37ffe3db86510


The web client
--------------
hector comes with a web interface written in PHP. Copy the files in phpstuff to your webserver directory:

    cp phpstuff/* localhost/hector


See the interface here: http://localhost/hector/ (depends on your webserver setup)
