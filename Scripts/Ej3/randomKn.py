#!/usr/bin/python

import sys
import random


n = int(sys.argv[1])
ejes = (n*(n-1))/2

target = open('../../Inputs/Ej3/randomK'+str(n)+'.txt', 'w')

target.write(str(n)+"\n")


u = 1
while(u <= n):
	v = u+1
	while(v <= n):
		esta = int(random.uniform(0,2))
		peso = int(random.uniform(-200,200))
		target.write(str(u) + " " + str(v) + " " + str(esta) + " " + str(peso)+"\n")
		v+=1
	u+=1 
target.write(str(-1))