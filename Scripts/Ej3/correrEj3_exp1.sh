#!/bin/bash
current=$(dirname $0)
cd $current

printf '%s\n' "Corriendo el experimento 1 del ejercicio 3, con n: "

#Crea directorios si no existe
mkdir -p ../../Outputs/Ej3/outsTiempo/exp1
mkdir -p ../../Inputs/Ej3/insTiempo/exp1

tams=(5 10 20 50 75 100 125 150 175 200)
cant_instancias=50
for((i = 0 ; i < ${#tams[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${tams[${i}]} "
	python random_ejer3_exp1.py ${tams[i]} $cant_instancias > ../../Inputs/Ej3/insTiempo/exp1/ej3_exp1_${tams[i]}
	../../tiempo 3 < ../../Inputs/Ej3/insTiempo/exp1/ej3_exp1_${tams[i]} >  ../../Outputs/Ej3/outsTiempo/exp1/ej3_exp1_${tams[i]}.csv
done
printf '%s\n'
