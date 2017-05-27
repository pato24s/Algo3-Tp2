#!/bin/bash
current=$(dirname $0)
cd $current

printf "Corriendo experimento 2 del ejercicio 3, con n = 100."

#Crea directorios si no existe
mkdir -p ../../Outputs/Ej3/outsTiempo/exp2
mkdir -p ../../Inputs/Ej3/insTiempo/exp2
 
n=100
cant_instancias=50

python ej3_exp2_Kn.py $n $cant_instancias > ../../Inputs/Ej3/insTiempo/exp2/ej3_exp2_K_$n
../../tiempo 3 < ../../Inputs/Ej3/insTiempo/exp2/ej3_exp2_K_$n >  ../../Outputs/Ej3/outsTiempo/exp2/ej3_exp2_K_$n.csv

python ej3_exp2_AGM.py $n $cant_instancias > ../../Inputs/Ej3/insTiempo/exp2/ej3_exp2_AGM_$n_$n
../../tiempo 3 < ../../Inputs/Ej3/insTiempo/exp2/ej3_exp2_AGM_$n >  ../../Outputs/Ej3/outsTiempo/exp2/ej3_exp2_AGM_$n.csv

printf '%s\n'
