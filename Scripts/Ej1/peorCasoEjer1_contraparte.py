#!/usr/bin/python

#recibe cuantos caminos y de que largo va a tener el grafo y lo crea haciendo que el camino que va
#de 1 a 2 sea el mas barato

import sys
import math
import random

cant_caminos = int(sys.argv[1])
largo_camino = int(sys.argv[2])
nodos = 1 + (largo_camino*cant_caminos) + 1 +1
ejes = ((largo_camino+1)*cant_caminos)+1	#Puede desde no tener aristas a ser completo


print str(nodos) + " " + str(ejes)
print str(1) + " " + str(nodos) + " " + str(0) 

camino_actual = 0
while(camino_actual < cant_caminos):
	nodo_actual = (largo_camino *camino_actual) + 2
	largo_actual = 0
	print str(1) + " " +str(nodo_actual) + " " + str(0) +" "+ str(camino_actual+1)
	while(largo_actual < largo_camino-1):
		if camino_actual==0:
			print str(nodo_actual) + " " + str(nodo_actual+1) +" "+ str(0) + " " + str(1)
		else:
			print str(nodo_actual) + " " + str(nodo_actual+1) +" "+ str(0) + " " + str(cant_caminos)
		nodo_actual+=1
		largo_actual+=1
	camino_actual+=1
	print str(nodo_actual) + " " + str(nodos-1) + " " +str(0) + " " + str(cant_caminos)
print str(nodos-1) + " " + str(nodos) + " " +str(0) + " " + str(1)

print "-1 -1"