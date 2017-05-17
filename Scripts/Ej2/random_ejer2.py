#!/usr/bin/python

#python random_ejer2.py tam_entradas cant_entradas > out.txt
#Crea cant_entradas de tam tam_entradas y las guarda en out.txt

import sys
import math
import random

nodos = int(sys.argv[1])
cant_entradas = int(sys.argv[2])

for c in range(0, cant_entradas):
	ejes = int(random.uniform(0, nodos * (nodos - 1) / 2) + 1)	#Puede desde no tener aristas a ser completo

	Matrix = [[0 for x in range(nodos)] for y in range(nodos)] 


	print str(nodos) + " " + str(ejes)
	flag_forzar_Max = 0
	i = 0
	while(i < ejes):
		c1 = int(random.uniform(1, nodos + 1))
		c2 = int(random.uniform(1, nodos + 1))
		while c2 == c1:
			c2 = int(random.uniform(1, nodos + 1))
		
		peso = int(random.uniform(0, 51))	#Peso entre 0 y 50 incluido
		if flag_forzar_Max == 0:	
			flag_forzar_Max = 1
			peso = 75
		if Matrix[c1 - 1][c2 - 1] == 0:
			Matrix[c1 - 1][c2 - 1] = 1
			# Matrix[c2 - 1][c1 - 1] = 1
			print str(c1) + " " + str(c2) + " " + str(peso)
			i += 1
print "-1 -1"