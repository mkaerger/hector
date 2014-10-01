-- Check, if pgcrypto works:
-- SELECT encode(digest('Some string...', 'sha256'), 'hex'); 

CREATE TYPE TY_CARD AS ENUM ('Credit', 'Debit');
CREATE TYPE TY_PROVIDER AS ENUM ('MasterCard', 'Visa', 'American Express', 'JCB', 'Discover');

CREATE TABLE cc_data (pan varchar(16), masked_pan varchar(65), token varchar(65) UNIQUE, provider TY_PROVIDER, card_type TY_CARD, date_created timestamp NOT NULL default now(), date_last_access timestamp NOT NULL);
CREATE INDEX pan_idx ON cc_data(pan);
CREATE INDEX token_idx ON cc_data(token);
