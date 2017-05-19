#!/bin/bash
current=$(dirname $0)
cd $current


#Crea directorios si no existe
mkdir -p ../../Inputs/Ej1/insTiempo/exp2
mkdir -p ../../Outputs/Ej1/outsTiempo/exp2

perct_premiums=(5 10 20 50 75 100)
for((i = 0 ; i < ${#perct_premiums[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${perct_premiums[${i}]} "
	python random_ejer1_exp2.py ${perct_premiums[i]} 50 > ../../Inputs/Ej1/insTiempo/exp2/ej1_exp2_${perct_premiums[i]}
	../../tiempo 1 < ../../Inputs/Ej1/insTiempo/exp2/ej1_exp2_${perct_premiums[i]} >  ../../Outputs/Ej1/outsTiempo/exp2/prueba_exp2_${perct_premiums[i]}.csv
done
printf '%s\n'