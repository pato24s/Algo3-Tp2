#!/bin/bash
current=$(dirname $0)
cd $current


#Crea directorios si no existe
mkdir -p ../../Inputs/Ej1/insTiempo/exp2
mkdir -p ../../Outputs/Ej1/outsTiempo/exp2

cant_caminos=(5 5 5 5 5 20 20 20 20 20)
k=(1 2 3 4 5 1 5 10 15 20)
cant_instancias=50

for((i = 0 ; i < ${#cant_caminos[@]}; i+=1));do
	# echo ${i}
	
	printf '%s\n' "${cant_caminos[${i}]}, ${k[${i}]} "
	python ej1_exp2.py ${cant_caminos[i]} ${k[i]} $cant_instancias > ../../Inputs/Ej1/insTiempo/exp2/ej1_exp2_${cant_caminos[i]}_${k[i]}
	../../tiempo 1 < ../../Inputs/Ej1/insTiempo/exp2/ej1_exp2_${cant_caminos[i]}_${k[i]} >  ../../Outputs/Ej1/outsTiempo/exp2/ej1_exp2_${cant_caminos[i]}_${k[i]}.csv
done
