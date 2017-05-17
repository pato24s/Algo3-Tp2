#!/usr/bin/python

import sys
import math
import random
import numpy as np


#levanto parametros
perct_const = int(sys.argv[1])
cant_entradas = int(sys.argv[2])

#hardcodeo n y m
n = 100
ejes = (n*(n-1))/2

for c in range(0,cant_entradas):
	#sorteo quienes van a ser las construidas utilizando el porcentaje pasado por parametro
	existe = np.random.choice(2, ejes, p=[1-(perct_const/100.0),perct_const/100.0])
	print n
	numeroArista = 0
	u = 1
	while (u <= n):
		v = u+1
		while(v<=n):
			esta = existe[numeroArista]
			numeroArista+=1
			peso = int(random.uniform(0,300))
			print str(u) + " " + str(v) + " " + str(esta) + " " + str(peso)
			v+=1
		u+=1 
print "-1"

