#!/bin/bash
current=$(dirname $0)
cd $current

#Crea directorios si no existe
mkdir -p ../../Outputs/Ej3/outsTiempo/exp2
mkdir -p ../../Inputs/Ej3/insTiempo/exp2

perct=(0 5 10 25 50 75 100 )
for((i = 0 ; i < ${#perct[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${perct[${i}]} "
	python random_ejer3_exp2.py ${perct[i]} 50 > ../../Inputs/Ej3/insTiempo/exp2/ej3_exp2_${perct[i]}
	../../tiempo 3 < ../../Inputs/Ej3/insTiempo/exp2/ej3_exp2_${perct[i]} >  ../../Outputs/Ej3/outsTiempo/exp2/prueba_exp2_${perct[i]}.csv
done
printf '%s\n'
