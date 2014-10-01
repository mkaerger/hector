echo -n "
<iban_registry>
<acquirers>";
cat bin_list | while read line; 
do echo -n " 
<acquirer>
<bank>";
echo -n $line | cut -d"|" -f2 | tr -d '\n'; echo "</bank>"; 
echo -n "<pan_range>";echo -n $line | cut -d"|" -f1 | tr -d '\n';echo "</pan_range>"; 
echo -n "</acquirer>";
done;
echo -n "
</acquirers>
</iban_registry>";
