
for i in `seq 1 1000000`; 
	do 

	BLOCK1=`tr -dc 1-9 </dev/urandom | head -c 4`
	BLOCK2=`tr -dc 1-9 </dev/urandom | head -c 4`
	BLOCK3=`tr -dc 1-9 </dev/urandom | head -c 4`
	BLOCK4=`tr -dc 1-9 </dev/urandom | head -c 4`
	
	echo $BLOCK1-$BLOCK2-$BLOCK3-$BLOCK4; 
	
	done;
