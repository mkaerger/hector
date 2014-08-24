-- SELECT encode(digest('bluefdfdf', 'sha256'), 'hex'); 

CREATE TYPE TY_CARD AS ENUM ('Credit', 'Debit');
CREATE TYPE TY_PROVIDER AS ENUM ('MasterCard', 'Visa', 'American Express', 'JCB', 'Discover');


CREATE TABLE cc_data (pan varchar(16), masked_pan varchar(65), token varchar(65) UNIQUE, provider TY_PROVIDER, card_type TY_CARD, date_created timestamp NOT NULL default now(), date_last_access timestamp NOT NULL);
CREATE INDEX pan_idx ON cc_data(pan);
CREATE INDEX token_idx ON cc_data(token);

--CREATE TABLE bin_range (range varchar(16), provider_info varchar(65), card_type TY_CARD);
--CREATE INDEX bin_range_idx ON bin_range(range);

--INSERT INTO cc_data values('1234567890123456', '3b7c241dca8d7f499d5498dd580d1cb18fb7031751e2487a9e02f38aa94ca4ad', '3b7c241dca8d7f499d5498dd580d1cb18fb7031751e2487a9e02f38aa94ca4ad', 'JCB', 'Debit', now(), now());
