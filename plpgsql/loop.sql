CREATE OR REPLACE FUNCTION ins() RETURNS BOOLEAN AS '

BEGIN

FOR i IN 1..10000000 LOOP
    -- some computations here
    -- INSERT INTO tokens VALUES (md5(random()::text), ''444'');

    INSERT INTO cc_data values(trunc(random() * 160009008000600 +4)::text, encode(digest(trunc(random() * 10000000000)::text, ''sha256''), ''hex''), encode(digest(trunc(random() * 10000000000)::text, ''sha256''), ''hex''), ''JCB'', ''Debit'', now(), now());


END LOOP;

return 1;
END;
' LANGUAGE plpgsql;



