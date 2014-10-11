echo -n "
<registry>
<issuers>";
cat ../ressources/bin_list | while read line; 
do 
PAN_RANGE_FROM=`echo $line | cut -d"|" -f1 | tr -d '\n'`
PAN_RANGE_TO=`echo $line | cut -d"|" -f2 | tr -d '\n'`
for i in `seq $PAN_RANGE_FROM $PAN_RANGE_TO`; 
do
RES=$i;
PAN_RANGE=`echo $RES | tr -d '\n'`
BANK=`echo $line | cut -d"|" -f3 | tr -d '\n'`
CARD_TYPE=`echo $line | cut -d"|" -f4 | tr -d '\n'`
echo -n " 
<issuer>
<bank>";
echo -n $BANK; echo "</bank>"; 
echo -n "<pan_range>";echo -n $PAN_RANGE; echo "</pan_range>"; 
echo -n "<card_type>";echo -n $CARD_TYPE; echo "</card_type>"; 
echo -n "</issuer>";
done;
done;
echo -n "
</issuers>
</registry>";
