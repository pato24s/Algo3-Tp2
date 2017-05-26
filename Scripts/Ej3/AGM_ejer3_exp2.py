#!/usr/bin/python

import sys
import random


n = 100
cant_entradas = 100
ejes = n-1

for c in range(0, cant_entradas):
	print n
	u = 1
	v = u+1
	while(u <= n):
		esta = 1
		peso = int(random.uniform(0,300))
		print str(u) + " " + str(v) + " " + str(esta) + " " + str(peso)
		v+=1
#Hasta aca 1 se conecta con todos (construidas), por lo que tenemos n-1 arista y por ende es un arbol.

#Vamos a hacer ahora que a partir de la ciudad 2 se conecte con todas (no construidas), luego 3 se conecta con todas (no construidas) , etc....	
	u = 2
	while(u <= n):
		v = u+1
		while(v <= n):
			esta = 0
			peso = int(random.uniform(0,300))
			print str(u) + " " + str(v) + " " + str(esta) + " " + str(peso)
			v+=1
		u+=1 
print "-1"
