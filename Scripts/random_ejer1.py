#!/usr/bin/python

import sys
import math
import random
import networkx as nx
import matplotlib.pyplot as plt


G=nx.Graph()


nodos = int(sys.argv[1])
ejes = int(sys.argv[2])
G.add_nodes_from([0,nodos-1])

Matrix = [[0 for x in range(nodos)] for y in range(nodos)] 





print str(nodos) + " " + str(ejes)

src = int(random.uniform(0,nodos))
dst = int(random.uniform(0,nodos))
while dst == src:
	dst = int(random.uniform(0,nodos))

k = int(random.uniform(0,ejes/2))
print str(src)+" "+str(dst)+" "+str(k)

i = 0
while(i < ejes):
	c1 = int(random.uniform(0,nodos))
	c2 = int(random.uniform(0,nodos))
	while c2 == c1:
		c2 = int(random.uniform(0,nodos))
	premium = int(random.uniform(0,2))
	peso = int(random.uniform(0,30))


	if Matrix[c1][c2] == 0:
		G.add_edge(c1, c2, weight=peso )
		Matrix[c1][c2]=1
		Matrix[c2][c1]=1
		print str(c1) + " " +str(c2)+" "+ str(premium) + " " + str(peso)
		i+=1
pos=nx.spring_layout(G)
nx.draw(G,pos,with_labels=True)
# specifiy edge labels explicitly
# edge_labels=dict([((u,v,),d['weight'])
#              for u,v,d in G.edges(data=True)])
# nx.draw_networkx_edge_labels(G,pos,edge_labels=edge_labels)
plt.savefig("path.png")