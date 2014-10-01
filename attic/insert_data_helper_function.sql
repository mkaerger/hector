CREATE OR REPLACE FUNCTIOn insert_cc(
	varchar(16),
	ty_provider,
	ty_card
) RETURNS BOOLEAN AS '

DECLARE
  pan ALIAS       FOR $1;
  provider ALIAS  FOR $2;
  card_type ALIAS FOR $3;

  BEGIN

  INSERT INTO cc_data values(
	pan, 
	encode(digest(pan, ''sha256''), ''hex''), 
	encode(digest(pan, ''sha256''), ''hex''), 
	provider, 
	card_type, 
	now(), 
	now()
	);

  return 1;
  END;
' LANGUAGE plpgsql;



