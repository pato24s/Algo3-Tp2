#!/bin/bash
current=$(dirname $0)
cd $current

printf '%s\n' "Corriendo el experimento 1 del ejercicio 2, con maxPeaje = 50 y n: "

#Crea directorios si no existe
mkdir -p ../../Inputs/Ej2/insTiempo/exp1
mkdir -p ../../Outputs/Ej2/outsTiempo/exp1

tams=(5 10 20 50 75 100 125 150 175 200 225 250 275 300 325 350 375 400)
max_peaje=50
cant_instancias=50

for((i = 0 ; i < ${#tams[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${tams[${i}]} "
	python ejer2_exp.py ${tams[i]} $max_peaje $cant_instancias > ../../Inputs/Ej2/insTiempo/exp1/ej2_exp1_${tams[i]}
	../../tiempo 2 < ../../Inputs/Ej2/insTiempo/exp1/ej2_exp1_${tams[i]} >  ../../Outputs/Ej2/outsTiempo/exp1/prueba_exp1_${tams[i]}.csv
done
printf '%s\n'