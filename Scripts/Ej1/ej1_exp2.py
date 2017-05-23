#!/usr/bin/python

#python premium_gen.py pct_premiums pct_usables cant_entradas  > out.txt
#Crea cant_entradas instancias de tam 200 y las guarda en out.txt

import sys
import math
import random

pct_premiums = int(sys.argv[1])
pct_usables = int(sys.argv[2])
cant_entradas = int(sys.argv[3])


#hardcodeo n 
nodos = 200

for c in range(0, cant_entradas):
	
	ejes = ((nodos - 1) * (nodos - 2)) / 2	#Asegura que el grafo es conexo
	
	prems = int(pct_premiums * ejes / float(100))	#Cantidad de premiums que depende de la cantidad de ejes
	
	k = int(pct_usables * prems / float(100))  #La cant maxima de premiums depende del parametro la cant de premiums
	
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
		#No permito una arista entre src y dst
		while c2 == c1  or ((c1 == src and c2 == dst) or (c1 == dst and c2 == src)):
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
		#No permito una arista entre src y dst
		while c2 == c1 or ((c1 == src and c2 == dst) or (c1 == dst and c2 == src)):
			c2 = int(random.uniform(1, nodos + 1))
		premium = 0
		peso = int(random.uniform(0, 51))	#Peso entre 0 y 50 incluido


		if Matrix[c1 - 1][c2 - 1] == 0:
			Matrix[c1 - 1][c2 - 1] = 1
			Matrix[c2 - 1][c1 - 1] = 1
			print str(c1) + " " + str(c2) + " " + str(premium) + " " + str(peso)
			i += 1
print "-1 -1"
