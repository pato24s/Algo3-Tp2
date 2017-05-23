#!/usr/bin/python

import sys
import math
import random
import numpy as np


#levanto parametros
perct_prems = int(sys.argv[1])
perct_usable = int(sys.argv[2])
cant_entradas = int(sys.argv[3])

#hardcodeo n y m
n = 200
ejes = ((n-1)*(n-2))/2 #Esto asegura que el grafo es conexo

for c in range(0,cant_entradas):
	
	#veo cual es mi k
	cantPrems=(perct_prems*ejes)/100
	k = (perct_usable*cantPrems)/100

	Matrix = [[0 for x in range(n)] for y in range(n)] 

	#ya tengo todo lo necesario, empiezo a printear
	print str(n) + " " +  str(ejes) 

	src = int(random.uniform(1, n + 1))
	dst = int(random.uniform(1, n + 1))
	#Me aseguro de que dst != src
	while dst == src:
		dst = int(random.uniform(1, n + 1))

	print str(src) + " " + str(dst) + " " + str(k)

	i = 0
	while(i < ejes):
		c1 = int(random.uniform(1, n + 1))
		c2 = int(random.uniform(1, n + 1))
		while c2 == c1:
			c2 = int(random.uniform(1, n + 1))
		premium = esPrem[i]
		peso = int(random.uniform(1, 51))	#Peso entre 0 y 50 incluido

		if Matrix[c1 - 1][c2 - 1] == 0:
			Matrix[c1 - 1][c2 - 1] = 1
			Matrix[c2 - 1][c1 - 1] = 1
			print str(c1) + " " + str(c2) + " " + str(premium) + " " + str(peso)
			i += 1
print "-1 -1"