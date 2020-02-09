rm(list=ls())

## La ganancia del módulo mic-max9814 se conecta a vcc para tener la mínina, con otras ganancias se saturaba a partir de 78dbs

## https://www.szynalski.com/tone-generator/
## 1 -> sonido ambiente
## 2 -> 1%
## 3 -> 5%
## 4 -> 7%
## 5 -> 10%
## 6 -> 13%
## 7 -> 18%
## 8 -> 25%
## 9 -> 35%
## 10 -> 50%
## 11 -> 60%
## 12 -> 70%
## 13 -> 80%
## 14 -> 90%

mean(c(512,515,516,516,515,511,515,517,518,515,513,515,515,517,513,515,508,513,516,513,515,517,511,519,517,513,517,519,517,516,521,513,515,507))

micAnalogValues <- c(7.758621,11.40909,25.80556,35.56757,47.35897,60.57895,76.10526,103.1081,138.9167,149,174.8621,228.1034,245.7059,275.4545,309.8095,505.3333,514.8529)
meterDbs <- c(32.7,37.7,50.8,52.7,55.1,57.5,60.5,63,65.6,67,68.4,71.3,72.1,73,73.4,79.7,83.3)

scatter.smooth(x=meterDbs, y=micAnalogValues, main="DBs ~ ADC")
plot(x=meterDbs, y=micAnalogValues, main="DBs ~ ADC")

cor(meterDbs, micAnalogValues)
lm(meterDbs ~ micAnalogValues)

ADC <- micAnalogValues

## Ajustado a ojo
Dbs <- (ADC)*0.07447 + 39.82947

1/0.07447

scatter.smooth(x=meterDbs, y=dbs, main="DBs ~ ADC")
plot(1:length(dbs), y=dbs)

## Call:
##     lm(formula = meterDbs ~ micAnalogValues)

## Coefficients:
##     (Intercept)  micAnalogValues  
## 49.82947          0.07447  


d <- ## output de consola serial
    plot(d, type =  'l')

## https://circuitdigest.com/microcontroller-projects/arduino-sound-level-measurement/
## ADC = (11.003* dB) – 83.2073
## (ADC+83.2073) / 11.003
