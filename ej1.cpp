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
		int V;
	private:

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

int proximoNodo(pair<int,int> dist[], bool visitados[], int V){
	int min= INT_MAX;
	int min_index;

	for (int i = 0; i < V; i++)
	{
		if(visitados[i] ==false && dist[i].first <=min){
			min = dist[i].first;
			min_index = i;
		}
	}
	return min_index;
}

int ejercicio1(Graph &grafo,int src, int dest, int k ){
	int V = grafo.V;
	pair<int,int> dist[V];
	bool visitados[V];

	pair<int,int> tuplaINF(INT_MAX,0);
	pair<int,int> tuplaCero(0,0);

	for(int i =0; i<V;i++){
		dist[i]=tuplaINF;
		visitados[i]=false;
	}

	dist[src]=tuplaCero;


	for (int count = 0; count < V-1; count++){

		int elegido = proximoNodo(dist,visitados, V);
		bool marcarPadre = false;
		visitados[elegido] = true;

		for (int v = 0; v < V; v++){
			
			if(!visitados[v] && grafo.matriz[elegido][v].first && dist[elegido].first != INT_MAX && dist[elegido].first + grafo.matriz[elegido][v].first < dist[v].first){
				pair<int,int> aux(dist[elegido].first + grafo.matriz[elegido][v].first , dist[elegido].second + grafo.matriz[elegido][v].second );
				dist[v] = aux;
			}
			//si algun camino se pasa de k lo pongo como infinito
			if(dist[v].second>k){
				dist[v].first = INT_MAX;
				marcarPadre = true;
			}



		}
		//si despues de actualizar a todos el padre esta marcado
		if(marcarPadre){
			dist[elegido].first =INT_MAX;
			visitados[elegido] = false;
		}
	}
	if(dist[dest].first==INT_MAX)
		return -1;
	return dist[dest].first;	
}


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