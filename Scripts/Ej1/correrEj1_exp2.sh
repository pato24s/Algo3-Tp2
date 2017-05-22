#!/bin/bash
current=$(dirname $0)
cd $current


#Crea directorios si no existe
mkdir -p ../../Inputs/Ej1/insTiempo/exp2
mkdir -p ../../Outputs/Ej1/outsTiempo/exp2

pct_premiums=(100 100 100 50 50 50 0)
pct_k=(100 50 0 100 50 0 0)
cant_instancias=50

for((i = 0 ; i < ${#perct_premiums[@]}; i+=1));do
	# echo ${i}
	printf '%s%s\n' "${pct_premiums[${i}]} " "${pct_k[${i}]} "
	python ej1_exp2.py ${pct_premiums[i]} ${pct_k[i]} $cant_instancias > ../../Inputs/Ej1/insTiempo/exp2/ej1_exp2_${pct_premiums[i]}_${pct_k[i]}
	../../tiempo 1 < ../../Inputs/Ej1/insTiempo/exp2/ej1_exp2_${pct_premiums[i]}_${pct_k[i]} >  ../../Outputs/Ej1/outsTiempo/exp2/prueba_exp2_${pct_premiums[i]}_${pct_k[i]}.csv
done
printf '%s\n'