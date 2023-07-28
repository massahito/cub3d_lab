RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
RESET="\033[0m"
OK=$GREEN"OK"$RESET
NG=$RED"NG"$RESET


cleanup() {
	rm -f out cmp 	status 
}

assertfilename() {
	COMMAND="$1"
	shift
	printf '%-60s:' "[$COMMAND]"

	./cub3D "$COMMAND" >out
	echo $?>status
	# echo $COMMAND | grep "out"
	echo $COMMAND | grep "out" > /dev/null

	# 'grep'の結果によって出力を分岐
	if [ $? -eq 0 ]
	then
		echo "Err" >> cmp
	else
		echo "ok"  >>cmp
	fi

	diff cmp out > /dev/null && echo -e -n " diff $OK" || echo -e -n " diff $NG"
	
	echo
	cleanup
}

assertfilename 'ok.cub'
assertfilename 'map.cub';
assertfilename 'mapdasd.cub';
assertfilename 'outmap.cu';
assertfilename 'outmap.c';
assertfilename 'outmap.';
assertfilename 'outmap';
assertfilename 'outmap.cu';
assertfilename 'outmap.c';
assertfilename 'outmap.';
assertfilename 'outmap';
