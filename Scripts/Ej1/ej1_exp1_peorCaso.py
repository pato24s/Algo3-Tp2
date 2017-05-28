#!/usr/bin/python

#Recibe cuantos caminos y de que largo va a tener el grafo y lo crea distribuyendo los pesos de forma que
#Dijkstra tenga que ir alternando de camino en camino. Por ultimo recibe cuantas instancias se quieren.

import sys
import math
import random

cant_caminos = int(sys.argv[1])
largo_camino = int(sys.argv[2])
cant_instancias = int(sys.argv[3])
nodos = 1 + (largo_camino * cant_caminos) + 1 + 1
ejes = ((largo_camino + 1) * cant_caminos) + 1

for c in range(0, cant_instancias):
	print str(nodos) + " " + str(ejes)
	print str(1) + " " + str(nodos) + " " + str(0) 

	camino_actual = 0
	while(camino_actual < cant_caminos):
		nodo_actual = (largo_camino *camino_actual) + 2
		largo_actual = 0
		print str(1) + " " + str(nodo_actual) + " " + str(0) + " " + str(camino_actual+1)
		while(largo_actual < largo_camino-1):
			print str(nodo_actual) + " " + str(nodo_actual+1) +" "+ str(0) + " " + str(cant_caminos)
			nodo_actual += 1
			largo_actual += 1
		camino_actual += 1
		print str(nodo_actual) + " " + str(nodos-1) + " " + str(0) + " " + str(cant_caminos)
	print str(nodos-1) + " " + str(nodos) + " " + str(0) + " " + str(1)

print "-1 -1"