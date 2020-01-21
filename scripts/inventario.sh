#!/bin/bash

# items=( plantower leds gps dht11 )
items[0]="plantower"
items[1]="leds"

## se asume que costos.dat está un directorio encima del script
for i in "$items[@]"
do
    ledger -f ../costos.dat  reg inventario:ingreso:componente:"$items[i]"  >> inventario.txt
    echo "\n" >> inventario.txt
done



