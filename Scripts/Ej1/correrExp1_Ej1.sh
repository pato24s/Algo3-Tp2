#Crea directorios si no existe
mkdir -p ../../Inputs/Ej1/insTiempo
mkdir -p ../../Outputs/Ej1/outsTiempo

tams=(5 10 20 50 75 100 200 300 400 500 600 800)
for((i = 0 ; i < ${#tams[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${tams[${i}]} "
	python random_ejer1.py ${tams[i]} 50 > ../../Inputs/Ej1/insTiempo/ej1_${tams[i]}
	../../tiempo 1 < ../../Inputs/Ej1/insTiempo/exp1/ej1_exp1_${tams[i]} >  ../../Outputs/Ej1/outsTiempo/exp1/prueba_exp1_${tams[i]}.csv
done
printf '%s\n'