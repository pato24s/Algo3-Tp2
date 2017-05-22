#!/usr/bin/python

#python premium_gen.py perct_premiums cant_entradas  > out.txt
#Crea cant_entradas instancias de tam 200 y las guarda en out.txt

import sys
import math
import random

perct_premiums = int(sys.argv[1])
cant_entradas = int(sys.argv[2])

#hardcodeo n 
nodos = 200

for c in range(0, cant_entradas):
	
	ejes = int(random.uniform((nodos / 2), (nodos * (nodos - 1) / 2) + 1))	
	
	prems = int(random.uniform((ejes / 2), (ejes / 4) + 1))	#Cantidad de premiums que depende de la cantidad de ejes
	
	k = int((perct_premiums / float(100)) * prems)  #La cant maxima de premiums depende del parametro la cant de premiums
	
	Matrix = [[0 for x in range(nodos)] for y in range(nodos)] 


	print str(nodos) + " " + str(ejes)

	src = int(random.uniform(1, nodos + 1))
	dst = int(random.uniform(1, nodos + 1))
	#Me aseguro de que dst != src
	while dst == src:
		dst = int(random.uniform(1, nodos + 1))

	print str(src) + " " + str(dst) + " " + str(k)

	i = 0
	while(i < prems): # Creo al azar rutas premium
		c1 = int(random.uniform(1, nodos + 1))
		c2 = int(random.uniform(1, nodos + 1))
		while c2 == c1:
			c2 = int(random.uniform(1, nodos + 1))
		premium = 1
		peso = int(random.uniform(0, 51))	#Peso entre 0 y 50 incluido


		if Matrix[c1 - 1][c2 - 1] == 0:
			Matrix[c1 - 1][c2 - 1] = 1
			Matrix[c2 - 1][c1 - 1] = 1
			print str(c1) + " " + str(c2) + " " + str(premium) + " " + str(peso)
			i += 1

	i = 0
	while(i < (ejes - prems) ): #Creo al azar el resto de las no premium
		c1 = int(random.uniform(1, nodos + 1))
		c2 = int(random.uniform(1, nodos + 1))
		while c2 == c1:
			c2 = int(random.uniform(1, nodos + 1))
		premium = 0
		peso = int(random.uniform(0, 51))	#Peso entre 0 y 50 incluido


		if Matrix[c1 - 1][c2 - 1] == 0:
			Matrix[c1 - 1][c2 - 1] = 1
			Matrix[c2 - 1][c1 - 1] = 1
			print str(c1) + " " + str(c2) + " " + str(premium) + " " + str(peso)
			i += 1
print "-1 -1"