#Crea directorios si no existe
mkdir -p ../../Inputs/Ej2/insTiempo
mkdir -p ../../Outputs/Ej2/outsTiempo

tams=(5 10 20 50 75 100 200 300 400 500 600 800)
for((i = 0 ; i < ${#tams[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${tams[${i}]} "
	python random_ejer2.py ${tams[i]} 50 > ../../Inputs/Ej2/insTiempo/ej2_${tams[i]}
	../../tiempo 2 < ../../Inputs/Ej2/insTiempo/ej2_${tams[i]} >  ../../Outputs/Ej2/outsTiempo/prueba_${tams[i]}.csv
done
printf '%s\n'