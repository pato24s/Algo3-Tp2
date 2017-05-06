#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <utility>
using namespace std;

class Graph
{
	public:
		Graph(int V);
		~Graph(); 
		void agregarArista(int,int,int,bool);
		vector<vector<pair<int,bool> > > matriz; 
		int E;
	private:
		int V;

};
Graph::~Graph(){}

Graph::Graph(int Ve){
	vector<vector<pair<int,bool> > > mat;
	for (int i = 0; i < Ve; ++i){
		vector<pair<int,bool>> aux;

		pair<int,bool> pNull(0,false);
		for(int j=0;j<Ve;j++){
			aux.push_back(pNull);
		}
		mat.push_back(aux);
	}
	V=Ve;
	E=0;
	matriz=mat;
}

void Graph::agregarArista(int u, int v, int peso, bool premium){
	pair<int,bool> aux(peso,premium);
	matriz[u][v] = aux;
	matriz[v][u] = aux;
	E++;
}



int main(){   
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
        // cout<<"sol entrada "<<j<<": "<<ejercicio2(graph,maxPeaje)<<endl;

        for (int i = 0; i < V; ++i)
        {
        	for (int j = 0; j < V; ++j)
        	{
        		cout<<"("<<grafo.matriz[i][j].first<<";"<<grafo.matriz[i][j].second<<") ";
        	}
        	cout<<endl;
        }
        cout<<endl;
        cout<<grafo.E<<endl;
    }

    return 0;
}