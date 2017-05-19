#!/bin/bash
current=$(dirname $0)
cd $current

#Crea directorios si no existe
mkdir -p ../../Inputs/Ej2/insTiempo/exp1
mkdir -p ../../Outputs/Ej2/outsTiempo/exp1

tams=(5 10 20 50 75 100 200 300 400 500 600 800)
for((i = 0 ; i < ${#tams[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${tams[${i}]} "
	python random_ejer2_exp1.py ${tams[i]} 50 > ../../Inputs/Ej2/insTiempo/exp1/ej2_exp1_${tams[i]}
	../../tiempo 2 < ../../Inputs/Ej2/insTiempo/exp1/ej2_exp1_${tams[i]} >  ../../Outputs/Ej2/outsTiempo/exp1/prueba_exp1_${tams[i]}.csv
done
printf '%s\n'