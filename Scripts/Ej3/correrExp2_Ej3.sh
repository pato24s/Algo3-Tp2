#Crea directorios si no existe
mkdir -p ../../Outputs/Ej3/outsTiempo
mkdir -p ../../Inputs/Ej3/insTiempo

perct=(0 5 10 25 50 75 100 )
for((i = 0 ; i < ${#perct[@]}; i+=1));do
	# echo ${i}
	printf '%s\n' "${perct[${i}]} "
	python generadorPerctConstruidas.py ${perct[i]} 50 > ../../Inputs/Ej3/insTiempo/ej3_exp2_${perct[i]}
	../../tiempo 3 < ../../Inputs/Ej3/insTiempo/ej3_exp2_${perct[i]} >  ../../Outputs/Ej3/outsTiempo/prueba_exp2_${perct[i]}.csv
done
printf '%s\n'
