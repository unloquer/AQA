#!/bin/bash
source 'lib.trap.sh'
usage="$(basename "$0")   <USER> <PATH> [-h]  -- program to generate mobile measurments

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

# passed arguments 
id=$1
myFile=$2;

i=2;
# while number of lines of a file
while(true)
do
    pm25=$(awk -v iter=$i -F, 'NR==iter {print $12}' $myFile)
    lat=$(awk -v iter=$i -F, 'NR==iter {print $2}' $myFile)
    lng=$(awk -v iter=$i -F, 'NR==iter {print $3}' $myFile)
    #interval=$(awk -v iter=$i -F, 'NR==iter {print $8}' $myFile) # TODO: how to translate velocity to sleep time?
    curl -i -XPOST 'http://localhost:8086/write?db=aqaTest' --data-binary "$id,id=$id pm25=$pm25,lat=$lat,lng=$lng";
    # time = distance/speed
    sleep  1; # 100/time;
    i=$((i+1))
done
exit 0
