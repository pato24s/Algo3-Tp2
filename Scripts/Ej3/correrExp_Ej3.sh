#Crea directorios si no existe
mkdir -p ../../Outputs/Ej3/outsTiempo
mkdir -p ../../Inputs/Ej3/insTiempo

tams=(5 10 20 50 75 100)
for((i = 0 ; i < 6; i+=1));do
	# echo ${i}
	printf '%s\n' "${tams[${i}]} "
	python randomKn.py ${tams[i]} 2 > ../../Inputs/Ej3/insTiempo/ej3_${tams[i]}
	#../../tiempo 3 < ../../Inputs/Ej3/insTiempo/ej3_${tams[i]} >  ../../Outputs/Ej3/outsTiempo/prueba_${tams[i]}.csv
done
printf '%s\n'
