#!/bin/bash

source 'lib.trap.sh'
usage="$(basename "$0")   [-h]  -- program to generate mobile measurments

where:
    -h  show this help text
    "

while getopts ':hs:' option; do
    case "$option" in
        h) echo "$usage"
           exit
           ;;
    esac
done
shift $((OPTIND - 1))
# query
bold=$(tput bold)

# init lat
# init lng
# init pm25

# infinite loop
while(true)
do
    pm25=$((1 + RANDOM % 200));
    lat=$(python -c "import random;print(random.uniform(6.150, 6.189))"); 
    lng=$(python -c "import random;print(random.uniform(-75.50, -75.59))"); 
    curl -i -XPOST 'http://localhost:8086/write?db=aqaTest' --data-binary "volkerX,id=volkerX pm25=$pm25,lat=$lat,lng=$lng";
    sleep 1;
done
exit 0
