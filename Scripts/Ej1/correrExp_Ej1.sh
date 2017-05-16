
tams=(5 10 20 50 75 100 200 500)
for((i = 0 ; i < 8; i+=1));do
	# echo ${i}
	printf '%s\n' "${tams[${i}]} "
	python random_ejer1.py ${tams[i]} 50 > ../../Inputs/Ej1/insTiempo/ej1_${tams[i]}
	../../tiempo 1 < ../../Inputs/Ej1/insTiempo/ej1_${tams[i]} >  ../../Outputs/Ej1/outsTiempo/prueba_${tams[i]}.csv
done
printf '%s\n'