#!/bin/bash
current=$(dirname $0)
cd $current

printf '%s\n' "Corriendo el experimento 2 del ejercicio 1, con cantidad de caminos y k:"

#Crea directorios si no existe
mkdir -p ../../Inputs/Ej1/insTiempo/exp2
mkdir -p ../../Outputs/Ej1/outsTiempo/exp2

cant_caminos=(8 8 8 8 8 10 10 10 10 10 12 12 12 12 12)
k=(1 3 5 7 8 1 3 5 8 10 1 3 5 10 12)
cant_instancias=50

for((i = 0 ; i < ${#cant_caminos[@]}; i+=1));do
	
	printf '%s\n' "${cant_caminos[${i}]}, ${k[${i}]} "
	python ej1_exp2.py ${cant_caminos[i]} ${k[i]} $cant_instancias > ../../Inputs/Ej1/insTiempo/exp2/ej1_exp2_${cant_caminos[i]}_${k[i]}
	../../tiempo 1 < ../../Inputs/Ej1/insTiempo/exp2/ej1_exp2_${cant_caminos[i]}_${k[i]} >  ../../Outputs/Ej1/outsTiempo/exp2/ej1_exp2_${cant_caminos[i]}_${k[i]}.csv
done
