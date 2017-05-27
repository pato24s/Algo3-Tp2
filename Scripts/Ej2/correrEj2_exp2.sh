#!/bin/bash
current=$(dirname $0)
cd $current

printf '%s\n' "Corriendo el experimento 2 del ejercicio 2, con n = 200 y maxPeaje: "

#Crea directorios si no existe
mkdir -p ../../Inputs/Ej2/insTiempo/exp2
mkdir -p ../../Outputs/Ej2/outsTiempo/exp2

tam=200
maxPeajes=(10 20 30 50 70 100 125 150 175 200 225 250 275 300 325 350 375 400)
cant_instancias=50
for((i = 0 ; i < ${#maxPeajes[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${maxPeajes[${i}]} "
	python ejer2_exp.py $tam ${maxPeajes[i]} $cant_instancias > ../../Inputs/Ej2/insTiempo/exp2/ej2_exp2_${maxPeajes[i]}
	../../tiempo 2 < ../../Inputs/Ej2/insTiempo/exp2/ej2_exp2_${maxPeajes[i]} >  ../../Outputs/Ej2/outsTiempo/exp2/ej2_exp2_${maxPeajes[i]}.csv
done
printf '%s\n'