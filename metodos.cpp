/* ------------------ Ejer 1 ------------------------------------- */

int proximoNodo(pair<int,int> dist[], bool visitados[], int V){
	int min = INT_MAX;
	int min_index;

	for (int i = 0; i < V; i++)
	{
		if(visitados[i] == false && dist[i].first <= min){
			min = dist[i].first;
			min_index = i;
		}
	}
	return min_index;
}

int ejercicio1(GrafoConPremium &grafo, int src, int dest, int k){
	bool termine = false;
	int V = grafo.V();
	pair<int, int> dist[V];
	bool visitados[V];

	pair<int, int> tuplaInf(INT_MAX, 0);
	pair<int, int> tuplaCero(0, 0);

	for(int i = 0; i < V; i++){
		dist[i] = tuplaInf;
		visitados[i] = false;
	}
	
	dist[src] = tuplaCero;
	int elegido = -1;
	
	while(!termine){ //ver si tengo que poner un int como cota o hacer un while hasta que distancias[dst] sea modificado
		elegido = proximoNodo(dist,visitados, V);
		cout<<elegido<<endl;
		bool marcarPadre = false;
		visitados[elegido] = true;
		if(elegido==dest){
			termine=true;
			break;
		}
		for (int v = 0; v < V; v++){
			
			if(!visitados[v] && grafo.matriz[elegido][v].first && dist[elegido].first != INT_MAX && dist[elegido].first + grafo.matriz[elegido][v].first < dist[v].first){
				pair<int,int> aux(dist[elegido].first + grafo.matriz[elegido][v].first , dist[elegido].second + grafo.matriz[elegido][v].second );
				dist[v] = aux;
				// cout<<"v en if: "<<v<<endl;
				if(dist[v].second>k){
					dist[v].first = INT_MAX;
					marcarPadre = true;
				}
			}
			//si algun camino se pasa de k lo pongo como infinito
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


/* ------------------ Ejer 2 ------------------------------------- */

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