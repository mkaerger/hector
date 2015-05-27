-- Check, if pgcrypto works:
-- SELECT encode(digest('Some string...', 'sha256'), 'hex'); 

CREATE TYPE TY_CARD AS ENUM ('Credit', 'Debit');
CREATE TYPE TY_BRANDS AS ENUM ('MasterCard', 'Visa', 'American Express', 'JCB', 'Discover', 'Diners Club', 'CUP');

CREATE TABLE cc_data (pan varchar(16), masked_pan varchar(65), token varchar(65) UNIQUE, issuer TY_issuer, card_type TY_CARD, date_created timestamp NOT NULL default now(), date_last_access timestamp NOT NULL);
CREATE INDEX pan_idx ON cc_data(pan);
CREATE INDEX token_idx ON cc_data(token);




-- test version
CREATE TABLE cc_data (pan varchar(16), masked_pan varchar(65), token varchar(65), issuer varchar(500), card_type varchar(65), date_created timestamp NOT NULL default now(), date_last_access timestamp NOT NULL);

-- test version / UNIQUE violation is catched --with-mysql, TODO --with-pgsql
CREATE TABLE cc_data (pan varchar(16) UNIQUE, masked_pan varchar(65), token varchar(65) UNIQUE, issuer varchar(500), card_type varchar(65), date_created timestamp NOT NULL default now(), date_last_access timestamp NOT NULL);


