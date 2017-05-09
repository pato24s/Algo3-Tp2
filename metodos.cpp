#include "metodos.h"	//Metodos de camino minimo

using namespace std;

/* ------------------ Ejer 1 ------------------ */

pair<int,int> proximoNodo(int filas, int cols, vector<vector<pair<int,int> > > &dist, vector<vector<bool> > &visitados){
	int min = INT_MAX;
    pair<int,int> min_ij;

    for (int i = 0; i < filas + 1; i++){
        for (int j = 0; j < cols; j++){
            if(visitados[i][j] == false && dist[i][j].first <= min){
            	pair<int,int> indices(i,j);
                min = dist[i][j].first;
                min_ij = indices;
            }    
        }
    }
    return min_ij;
}

int ejercicio1(GrafoConPremium &grafo, int src, int dest, int k){
    bool termine = false;
    int V = grafo.dameV();

	pair<int, int> tuplaCero(0, 0);
    pair<int, int> tuplaInf(INT_MAX, 0);
    vector<vector<pair<int,int> > > dist(k + 1, vector<pair<int,int> >(V, tuplaInf));
    vector<vector<bool> > visitados(k + 1, vector<bool>(V, false));
	dist[0][src] = tuplaCero;
	pair<int,int> elegido;
    
    //DEBUG
    int c = 0;
    for (int count = 0; count < (V*k) - 1; count++){
        if(termine){
           	break;
        }
        elegido = proximoNodo(k, V, dist, visitados);
        //DEBUG
        cout << "elegido: (" << elegido.first << "," << elegido.second + 1 << ")" << endl;
        int nivel = elegido.first;
        int nodo = elegido.second;

        //DEBUG
        if(nivel == dist[nivel][nodo].second){
        	c++;
        	cout << "Son iguales. C = " << c << endl;
        }

        int dist_elegido = dist[nivel][nodo].first;

        visitados[nivel][nodo] = true;
    
        
        for (int ik = 0; ik < k + 1; ik++){
            if(termine){
            	break;
            }
            for (int v = 0; v < V; v++){
                if(!visitados[ik][v] && ik == nivel && grafo.conectados(nodo,v) && dist_elegido != INT_MAX && 
                		dist_elegido + grafo.peso(nodo,v) < dist[ik][v].first){
                    
                    pair<int,int> tuplaCamino(dist_elegido + grafo.peso(nodo, v),
                    	 nivel + grafo.esPremium(nodo,v));

                    int nuevoNivel = nivel + grafo.esPremium(nodo,v);
                    if(nuevoNivel <= k){
                        dist[nuevoNivel][v] = tuplaCamino;
                        // cout<<"v: "<<v<<" ,ik: "<<ik<<endl;
                        cout<<" actualizando a: ("<< nuevoNivel <<"," << v + 1 <<") con valores: ("<< tuplaCamino.first<< "," << tuplaCamino.second <<")" << endl;
                        if(v == dest){
                        	termine = true;
                        	break;
                        }
                    }
                }
            }
        }
    }

    int result = INT_MAX;
    for(int i = 0; i < k + 1; i++){
        if(dist[i][dest].first < result){
            result = dist[i][dest].first;
        }
    }

    if(result == INT_MAX){
        return -1;
    }
    return result;

}


/* ------------------ Ejer 2 ------------------ */

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};
 
// a structure to represent a connected, directed and 
// weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
 
    // graph is represented as an array of edges.
    struct Edge* edge;
    void addEdge(int e,int u, int v, int w);
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = 
         (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = 
       (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}


//Funcion que agregue para que sea mas izi agregar aristas
void addEdge(struct Graph* g, int e,int u, int v, int w){
    g->edge[e].src = u;
    g->edge[e].dest = v;
    g->edge[e].weight = w;
}
 
// A utility function used to print the solution
void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
// The main function that finds shortest distances from src to
// all other vertices using Bellman-Ford algorithm.  The function
// also detects negative weight cycle
//BellmanFord robado, dada una ciudad source(src) calcula las distancias minimas entre source y el resto
//Tambien calcula la distancia entre source y source que es lo que necesitamos
// le agregue un k que es cuanto vamos a restarle a todos los peajes
bool BellmanFord(struct Graph* graph, int k)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
 
    // Step 1: Initialize distances from src to all other vertices
    // as INFINITE
    for (int i = 0; i < V; i++)
        dist[i]   = INT_MAX;
    dist[0] = 0;
 
    // Step 2: Relax all edges |V| - 1 times. A simple shortest 
    // path from src to any other vertex can have at-most |V| - 1 
    // edges
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight-k;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 
    // Step 3: check for negative-weight cycles.  The above step 
    // guarantees shortest distances if graph doesn't contain 
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.

    //Esta parte es lo que necesitamos en el punto 2!
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight-k;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            return true;
    }
    

    return false;
}
 
int ejercicio2(struct Graph* graph, int maxPeaje){
    int reduccion;
    
    bool perdemosPlata;
    int init=0;
    int fin=maxPeaje;
    int mid=(fin+init)/2;
    while(init<=fin){ //log(maxPeaje)
        reduccion=mid;
        
        perdemosPlata=BellmanFord(graph,reduccion);//creo que bellmanFord es n*m

        if(perdemosPlata){
        //si perdemos plata solucion esta entre init y mid (hay que reducir menos el precio)
            fin=mid-1;
        }else{
            //si no perdemos plata podemos aumentar la reduccion 
            //sol entre mid y fin
            init=mid+1;
        }
        mid=(init+fin)/2;

    }  
    return reduccion;
//me queda entonces O(n*m*log) ?
}