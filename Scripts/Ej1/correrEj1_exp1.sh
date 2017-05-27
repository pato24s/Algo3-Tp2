#!/bin/bash
current=$(dirname $0)
cd $current

printf '%s\n' "Corriendo el experimento 1 del ejercicio 1, con cantidad de caminos: "

#Crea directorios si no existe
mkdir -p ../../Inputs/Ej1/insTiempo/exp1
mkdir -p ../../Outputs/Ej1/outsTiempo/exp1

largo_camino=20
cant_caminos=(5 10 15 20 25 30 35 40 50 75 80 95 100 125 150 175 200)
cant_instancias=50

for((i = 0 ; i < ${#cant_caminos[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${cant_caminos[${i}]} "
	
	python ej1_exp1_buenCaso.py ${cant_caminos[i]} $largo_camino $cant_instancias > ../../Inputs/Ej1/insTiempo/exp1/ej1_exp1_buenCaso_${cant_caminos[i]}
	../../tiempo 1 < ../../Inputs/Ej1/insTiempo/exp1/ej1_exp1_buenCaso_${cant_caminos[i]} >  ../../Outputs/Ej1/outsTiempo/exp1/prueba_exp1_buenCaso_${cant_caminos[i]}.csv

	python ej1_exp1_peorCaso.py ${cant_caminos[i]} $largo_camino $cant_instancias > ../../Inputs/Ej1/insTiempo/exp1/ej1_exp1_peorCaso_${cant_caminos[i]}
	../../tiempo 1 < ../../Inputs/Ej1/insTiempo/exp1/ej1_exp1_peorCaso_${cant_caminos[i]} >  ../../Outputs/Ej1/outsTiempo/exp1/prueba_exp1_peorCaso_${cant_caminos[i]}.csv
done
printf '%s\n'