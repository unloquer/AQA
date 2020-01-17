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
    lat=$(python -c "import random;print(random.uniform(6.240, 6.249))"); 
    lng=$(python -c "import random;print(random.uniform(-75.580, -75.585))"); 
    curl -i -XPOST 'http://localhost:8086/write?db=aqaTest' --data-binary "volkerX,id=volkerX pm25=$pm25,lat=$lat,lng=$lng";
    sleep 1;
    pm25=$((1 + RANDOM % 200));
    lat=$(python -c "import random;print(random.uniform(6.260, 6.265))"); 
    lng=$(python -c "import random;print(random.uniform(-75.570, -75.575))"); 
    curl -i -XPOST 'http://localhost:8086/write?db=aqaTest' --data-binary "volkerX001,id=volkerX pm25=$pm25,lat=$lat,lng=$lng";
    pm25=$((1 + RANDOM % 200));
    lat=$(python -c "import random;print(random.uniform(6.250, 6.259))"); 
    lng=$(python -c "import random;print(random.uniform(-75.580, -75.589))"); 
    curl -i -XPOST 'http://localhost:8086/write?db=aqaTest' --data-binary "volkerX002,id=volkerX pm25=$pm25,lat=$lat,lng=$lng";
    sleep 1;
    pm25=$((1 + RANDOM % 200));
    lat=$(python -c "import random;print(random.uniform(6.230, 6.235))"); 
    lng=$(python -c "import random;print(random.uniform(-75.570, -75.575))"); 
    curl -i -XPOST 'http://localhost:8086/write?db=aqaTest' --data-binary "volkerX003,id=volkerX pm25=$pm25,lat=$lat,lng=$lng";
    sleep 1;
done
exit 0
