#Crea directorios si no existe
mkdir -p ../../Inputs/Ej2/insTiempo
mkdir -p ../../Outputs/Ej2/outsTiempo

pesos=(5 10 20 50 75 100 200 300 400 500 600 800)
for((i = 0 ; i < ${#pesos[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${pesos[${i}]} "
	python random_ejer2_exp2.py ${pesos[i]} 50 > ../../Inputs/Ej2/insTiempo/ej2_exp2_${pesos[i]}
	../../tiempo 2 < ../../Inputs/Ej2/insTiempo/exp2/ej2_exp2_${pesos[i]} >  ../../Outputs/Ej2/outsTiempo/exp2/prueba_exp2_${pesos[i]}.csv
done
printf '%s\n'