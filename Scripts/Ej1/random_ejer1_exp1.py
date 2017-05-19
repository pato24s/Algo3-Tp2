#!/usr/bin/python

#python random_ejer1.py tam_entradas cant_entradas > out.txt
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

	src = int(random.uniform(1, nodos + 1))
	dst = int(random.uniform(1, nodos + 1))
	#Me aseguro de que dst != src
	while dst == src:
		dst = int(random.uniform(1, nodos + 1))

	k = int(random.uniform(0,ejes / 2 + 1))
	print str(src) + " " + str(dst) + " " + str(k)

	i = 0
	while(i < ejes):
		c1 = int(random.uniform(1, nodos + 1))
		c2 = int(random.uniform(1, nodos + 1))
		while c2 == c1:
			c2 = int(random.uniform(1, nodos + 1))
		premium = int(random.uniform(0, 2))
		peso = int(random.uniform(0, 51))	#Peso entre 0 y 50 incluido


		if Matrix[c1 - 1][c2 - 1] == 0:
			Matrix[c1 - 1][c2 - 1] = 1
			Matrix[c2 - 1][c1 - 1] = 1
			print str(c1) + " " + str(c2) + " " + str(premium) + " " + str(peso)
			i += 1
print "-1 -1"