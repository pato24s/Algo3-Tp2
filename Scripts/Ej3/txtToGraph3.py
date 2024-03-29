#!/usr/bin/python

import sys
import math
import random
import networkx as nx
import matplotlib.pyplot as plt
from networkx.drawing.nx_agraph import graphviz_layout


G=nx.Graph()

linea0 = raw_input().split(' ')
nodos = int(linea0[0])
# ejes = int(linea0[1])
G.add_nodes_from([1,nodos])



i = 0
while(i < ((nodos*(nodos-1))/2)):
	lineaEje_i = raw_input().split(' ')
	c1 = int(lineaEje_i[0])
	c2 = int(lineaEje_i[1])
	existe = int(lineaEje_i[2])
	wt = int(lineaEje_i[3])
	color = 'k'
	if existe == 1:
		color = 'g'
	G.add_edge(c1, c2,color=color, weight=wt )
	i += 1


edges = G.edges()
colors = [G[u][v]['color'] for u,v in edges]
pos = nx.spectral_layout(G)
nx.draw_spectral(G, with_labels = True )
labels = nx.get_edge_attributes(G,'weight')
nx.draw_networkx_edge_labels(G, pos, edge_color = colors, edge_labels = labels)
nx.draw(G, pos, edges=edges, edge_color=colors)
plt.savefig("../../Outputs/Ej3/grafoEjer3.png")
