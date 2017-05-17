#!/usr/bin/python

#python random_ejer2.py peso_max cant_entradas > out.txt
#Crea cant_entradas de tam 200 y pMax peso_max y las guarda en out.txt

import sys
import math
import random

pMax = int(sys.argv[1])
cant_entradas = int(sys.argv[2])
nodos = 200

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
		
		peso = int(random.uniform(0, pMax))	#Peso entre 0 y pMax
		if flag_forzar_Max == 0:	#Fuerzo la existencia de una arista con peso = Pmax
			flag_forzar_Max = 1
			peso = pMax
		if Matrix[c1 - 1][c2 - 1] == 0:
			Matrix[c1 - 1][c2 - 1] = 1
			print str(c1) + " " + str(c2) + " " + str(peso)
			i += 1
print "-1 -1"