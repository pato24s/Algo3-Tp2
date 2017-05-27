#!/usr/bin/python

#python random_ejer2.py nodos maxPeaje cant_entradas > out.txt
#Crea cant_entradas de un digrafo que es un ciclo simple donde una arista tiene maxPeaje y las guarda en out.txt

import sys
import math
import random

nodos = int(sys.argv[1])
maxPeaje = int(sys.argv[2])
cant_entradas = int(sys.argv[3])

for c in range(0, cant_entradas):
	ejes = nodos
	print str(nodos) + " " + str(ejes)

	#Crea un ciclo simple dirigido. La arista de n a 1 tiene maxPeaje y el resto algo menor
	i = 1
	while(i <= nodos):
		c1 = i
		c2 = (i + 1) % nodos
		if(i != nodos):
			peso = int(random.uniform(0, maxPeaje))	#Peso entre 0 y maxPeaje sin incluir
		else:
			peso = maxPeaje
		print str(c1) + " " + str(c2) + " " + str(peso)

		i += 1
print "-1 -1"