#!/bin/sh
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

	./cub3D "$COMMAND" 2> out
	echo $?>status

    if cat out | grep -q "Error"; then
        echo "TEST $OK"
    else
        echo "TEST $NG"
    fi

	echo
	cleanup
}

cp ../../cub3D .
assertfilename 'map/out.cb'
assertfilename 'map/map.cub';
assertfilename 'map/map.cub.cub';
assertfilename 'map/map.cub.cub.cub';
assertfilename 'map/map.cub.cub.cub.cub.cub.cub.cub.cub.cub.cub.cub.cub';
assertfilename 'map/mapdasd.cub';
assertfilename 'map/outmap.cu';
assertfilename 'map/outmap.c';
assertfilename 'map/outmap.';
assertfilename 'map/outmap';
assertfilename 'map/outmap.cu';
assertfilename 'map/outmap.c';
assertfilename 'map/outmap.';
assertfilename 'map/outmap';

i=0
while [ $i -lt 61 ]; do
    filename=$(printf "map/map%02d.cub" $i)
    assertfilename $filename
    i=$((i + 1))
done
    assertfilename map/map101.cub
