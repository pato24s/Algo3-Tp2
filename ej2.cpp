#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
 using namespace std;
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
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight-k;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            return true;
        //     printf("Graph contains negative weight cycle");
    }
    
    // printArr(dist, V);

    //veo si puedo ir y volver a la ciudad source ganando plata
    //chequeo distancia de src a src
    // bool res=(dist[src]<0);
    return false;
    // return res;
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




// Driver program to test above functions
int main()
{   int j=0;
    while(1){
        int V;
        int E;
        cin >> V >> E;//proceso la primer linea
        if(V==-1)//si es la linea del -1 -1 chau
            break;

        struct Graph* graph = createGraph(V, E);//Creo grafo
        int c1;
        int c2;
        int p;
        int maxPeaje=-1000;
        for (int i = 0; i < E; ++i)
        {
            cin >> c1 >> c2 >> p;
            if(p>maxPeaje)
                maxPeaje=p;
            addEdge(graph,i,c1,c2,p);
        }
        cout<<"sol entrada "<<j<<": "<<ejercicio2(graph,maxPeaje)<<endl;
        j++;
    }

    return 0;
}