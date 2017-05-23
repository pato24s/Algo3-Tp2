#!/usr/bin/python

#Recibe cuantos caminos crear, en base a ese numero calcula el largo de los caminos como cant_caminos-1
#Recibe k
#Recibe cant de instancias

#Crea cant_instancias iguales en la que de "izquierda a derecha" cada camino tiene mas premiums que su siguiente y menos peso

import sys
import math
import random

cant_caminos = int(sys.argv[1])
k = int(sys.argv[2])
cant_instancias = int(sys.argv[3])
largo_camino = cant_caminos-1
nodos = 1 + (largo_camino * cant_caminos) + 1 + 1
ejes = ((largo_camino + 1) * cant_caminos) + 1

for c in range(0, cant_instancias):
	print str(nodos) + " " + str(ejes)
	print str(1) + " " + str(nodos) + " " + str(k) 

	camino_actual = 0
	while(camino_actual < cant_caminos):
		nodo_final = (largo_camino *camino_actual) + largo_camino+1
		nodo_ppio = (largo_camino *camino_actual) +2
		nodo_iter = nodo_final
		largo_actual = 0
		prems_camino = cant_caminos - (camino_actual + 1)
		prems_count = 0
		print str(1) + " " + str(nodo_ppio) + " " + str(0) + " " + str(3)
		while(largo_actual < largo_camino-1):
			esPrem = 0
			peso = 3
			if prems_count < prems_camino-1:
				esPrem = 1
				peso = 1
				prems_count+=1
			print str(nodo_iter) + " " + str(nodo_iter-1) +" "+ str(esPrem) + " " + str(peso)
			nodo_iter -= 1
			largo_actual += 1
		camino_actual += 1
		esPrem = 1
		peso = 1
		if camino_actual == cant_caminos:
			esPrem = 0
			peso = 3
		print str(nodo_final) + " " + str(nodos-1) + " " + str(esPrem) + " " + str(peso)
	print str(nodos-1) + " " + str(nodos) + " " + str(0) + " " + str(3)

print "-1 -1"