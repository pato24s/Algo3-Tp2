#!/bin/bash
current=$(dirname $0)
cd $current

#Crea directorios si no existe
mkdir -p ../../Outputs/Ej3/outsTiempo/exp2
mkdir -p ../../Inputs/Ej3/insTiempo/exp2
 
	#python K100_random_ejer3_exp2.py > ../../Inputs/Ej3/insTiempo/exp2/ej3_exp2_K100
	#../../tiempo 3 < ../../Inputs/Ej3/insTiempo/exp2/ej3_exp2_K100 >  ../../Outputs/Ej3/outsTiempo/exp2/prueba_exp2_K100.csv
	python AGM_ejer3_exp2.py > ../../Inputs/Ej3/insTiempo/exp2/ej3_exp2_AGM
	../../tiempo 3 < ../../Inputs/Ej3/insTiempo/exp2/ej3_exp2_AGM >  ../../Outputs/Ej3/outsTiempo/exp2/prueba_exp2_AGM.csv

printf '%s\n'
