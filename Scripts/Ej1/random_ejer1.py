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
		color = 'k'
		if premium ==1:
			color = 'b'
		G.add_edge(c1, c2,color=color, weight=peso )
		Matrix[c1][c2]=1
		Matrix[c2][c1]=1
		print str(c1) + " " +str(c2)+" "+ str(premium) + " " + str(peso)
		i+=1


edges = G.edges()
colors = [G[u][v]['color'] for u,v in edges]
pos=nx.circular_layout(G)
nx.draw_circular(G,with_labels=True )
labels = nx.get_edge_attributes(G,'weight')
nx.draw_networkx_edge_labels(G,pos,edge_color=colors,edge_labels=labels)
nx.draw(G, pos, edges=edges, edge_color=colors)
plt.savefig("random.png")