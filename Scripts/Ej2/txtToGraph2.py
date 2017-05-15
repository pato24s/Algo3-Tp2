#!/usr/bin/python

import sys
import math
import random
import networkx as nx
import matplotlib.pyplot as plt


G=nx.DiGraph()

linea0 = raw_input().split(' ')
nodos = int(linea0[0])
ejes = int(linea0[1])
G.add_nodes_from([1,nodos])

i = 0
while(i < ejes):
	lineaEje_i = raw_input().split(' ')
	c1 = int(lineaEje_i[0])
	c2 = int(lineaEje_i[1])
	wt = int(lineaEje_i[2])
	G.add_edge(c1, c2, weight=wt )

	i+=1


edges = G.edges()
pos=nx.spring_layout(G)
# nx.draw(G,with_labels=True )
labels = nx.get_edge_attributes(G,'weight')
nx.draw_networkx_edge_labels(G,pos,edge_labels=labels)
nx.draw(G,pos,with_labels=True,node_size=300, edges=edges)
plt.savefig("../../Outputs/Ej2/grafoEjer2.png")