echo -n "
<iban_registry>
<acquirers>";
cat ../ressources/bin_list | while read line; 
do 
PAN_RANGE_FROM=`echo $line | cut -d"|" -f1 | tr -d '\n'`
BANK=`echo $line | cut -d"|" -f3 | tr -d '\n'`
CARD_TYPE=`echo $line | cut -d"|" -f4 | tr -d '\n'`
echo -n " 
<acquirer>
<bank>";
echo -n $BANK; echo "</bank>"; 
echo -n "<pan_range>";echo -n $PAN_RANGE_FROM; echo "</pan_range>"; 
echo -n "<card_type>";echo -n $CARD_TYPE; echo "</card_type>"; 
echo -n "</acquirer>";
done;
echo -n "
</acquirers>
</iban_registry>";
