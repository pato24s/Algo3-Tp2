#!/usr/bin/python

import sys
import random


n = int(sys.argv[1])
cant_entradas = int(sys.argv[2])
ejes = (n*(n-1))/2

for c in range(0, cant_entradas):
	u = 1
	while(u <= n):
		v = u+1
		while(v <= n):
			esta = int(random.uniform(0,2))
			peso = int(random.uniform(0,300))
			print str(u) + " " + str(v) + " " + str(esta) + " " + str(peso)
			v+=1
		u+=1 
print "-1"