#!/bin/bash
current=$(dirname $0)
cd $current

#Crea directorios si no existe
mkdir -p ../../Outputs/Ej3/outsTiempo/exp1
mkdir -p ../../Inputs/Ej3/insTiempo/exp1

tams=(5 10 20 50 75 100 200)
for((i = 0 ; i < ${#tams[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${tams[${i}]} "
	python randomKn.py ${tams[i]} 50 > ../../Inputs/Ej3/insTiempo/exp1/ej3_exp1_${tams[i]}
	../../tiempo 3 < ../../Inputs/Ej3/insTiempo/exp1/ej3_exp1_${tams[i]} >  ../../Outputs/Ej3/outsTiempo/exp1/prueba_exp1_${tams[i]}.csv
done
printf '%s\n'
