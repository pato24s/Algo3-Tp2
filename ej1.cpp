#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <utility>
#include "grafos.h"		//Clases de grafos
#include "metodos.h"	//Metodos de camino minimo

using namespace std;

int main(){   
    int j=0;
    while(1){
        int V;
        int E;
        cin >> V >> E;//proceso la primer linea
        if(V==-1)//si es la linea del -1 -1 chau
            break;
        int src;
        int dst;
        int k;
        cin >> src >> dst >> k;

        // struct Graph* graph = createGraph(V, E);//Creo grafo
        Graph grafo(V);
        int c1;
        int c2;
        bool premium;
        int peso;
        for (int i = 0; i < E; ++i)
        {
            cin >> c1 >> c2 >> premium >> peso;
          	grafo.agregarArista(c1,c2,peso,premium);
            // addEdge(graph,i,c1,c2,p);
        }

        for (int i = 0; i < V; ++i)
        {
        	for (int j = 0; j < V; ++j)
        	{
        		cout<<"("<<grafo.matriz[i][j].first<<";"<<grafo.matriz[i][j].second<<") ";
        	}
        	cout<<endl;
        }
        cout<<endl;
        // cout<<grafo.E<<endl;
        // cout<<"src: "<<src<<" dst: "<<dst<<" k: "<<k<<endl;
        cout<<"salida instancia "<<j<<": "<<ejercicio1(grafo,src,dst,k)<<endl;
        j++;
    }

    return 0;
}