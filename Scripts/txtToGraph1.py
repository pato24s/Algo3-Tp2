#!/usr/bin/python

import sys
import math
import random
import networkx as nx
import matplotlib.pyplot as plt


G=nx.Graph()

linea0 = raw_input().split(' ')
nodos = int(linea0[0])
ejes = int(linea0[1])
G.add_nodes_from([1,nodos])

linea1 = raw_input().split(' ')
src = linea1[0]
dst = linea1[1]
k = linea1[2]

i = 0
while(i < ejes):
	lineaEje_i = raw_input().split(' ')
	c1 = int(lineaEje_i[0])
	c2 = int(lineaEje_i[1])
	pm = int(lineaEje_i[2])
	wt = int(lineaEje_i[3])
	color = 'k'
	if pm ==1:
		color = 'b'
	G.add_edge(c1, c2,color=color, weight=wt )
	i+=1


edges = G.edges()
colors = [G[u][v]['color'] for u,v in edges]
pos=nx.circular_layout(G)
nx.draw_circular(G,with_labels=True )
labels = nx.get_edge_attributes(G,'weight')
nx.draw_networkx_edge_labels(G,pos,edge_color=colors,edge_labels=labels)
nx.draw(G, pos, edges=edges, edge_color=colors)
plt.savefig("grafo.png")