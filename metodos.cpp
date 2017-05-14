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
bool BellmanFord(DigrafoConPeso g, int k)
{
    int V = g.dameV();
    int E = g.dameE();
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
        for (std::set<Eje>::iterator it=g.aristasInicio(); it!=g.aristasFin(); ++it)
        {
            int u = (*it).dameU();
            int v = (*it).dameV();
            int weight = (*it).damePeso()-k;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 
    // Step 3: check for negative-weight cycles.  The above step 
    // guarantees shortest distances if graph doesn't contain 
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.

    //Esta parte es lo que necesitamos en el punto 2!
    for (std::set<Eje>::iterator it=g.aristasInicio(); it!=g.aristasFin(); ++it)
    {
        int u = (*it).dameU();
        int v = (*it).dameV();
        int weight = (*it).damePeso()-k;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            return true;
    }
    

    return false;
}
 


int ejercicio2(DigrafoConPeso g, int maxPeaje){
    int reduccion;
    
    bool perdemosPlata;
    int init=0;
    int fin=maxPeaje;
    int mid=(fin+init)/2;
    while(init<=fin){ //log(maxPeaje)
        reduccion=mid;
        
        perdemosPlata=BellmanFord(g,reduccion);//creo que bellmanFord es n*m

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
}

/* ------------------ Ejer 3 ------------------ */

int altura[1000000];
int padre[1000000];



void kruskal_init(int n) {
    for (int i = 1; i < n; ++i){
              altura[i]=1;
              padre[i] = i;
        }    

}

int kruskal_find(int x) {
    if(padre[x] != x){
        padre[x] = kruskal_find(padre[x]);
    }
    return padre[x];
}

void kruskal_uni(int x, int y) {
    x = kruskal_find(x);
    y = kruskal_find(y);
    if(altura[x] < altura[y]){
        padre[x] = y;
    }else{
        padre[y] = x;
    }

    if(altura[x]==altura[y]){
        altura[x] = altura[x]+1;
    }
}



int ejercicio3(GrafoConPeso &g){
    //Kruskal modificado
    int costo = 0;
    int Ve = g.dameV();


    //para debugear
    cout<<"lista de aristas: "<<endl;
    for (std::set<Eje>::iterator it=g.aristasInicio(); it!=g.aristasFin(); ++it)
    {
        int u = (*it).dameU();
        int v = (*it).dameV();
        int weight = (*it).damePeso();
        cout<<"("<<u<<","<<v<<") p: "<<weight<<endl;
    }
    
    vector<pair<int,int> > solucion_ejes;
    kruskal_init(Ve);

    std:set<Eje>::iterator iter = g.aristasInicio();
    for (int j = 0; j < g.dameE(); ++j){
        int eje_u = (*iter).dameU();
        int eje_v = (*iter).dameV();
        int eje_p = (*iter).damePeso();

        if(kruskal_find(eje_u) != kruskal_find(eje_v)){
            cout<<"sirve eje: ("<<eje_u<<" "<<eje_v<<")"<<endl;
            //Agrego el eje a la solucion
            pair<int,int> ejeValido(eje_u,eje_v);
            solucion_ejes.push_back(ejeValido);
            
            //Si el peso era negativo no agrego el costo (ya la tengo construida)
            if(eje_p>0){
                costo += eje_p;
            }

            //Uno las componentes
            kruskal_uni(eje_u,eje_v);


        }else{
            //no sirve la arista, si estaba construida tengo que agregar costo de destruccion
            if(eje_p<0){
                costo += (eje_p)*(-1);
            }
        }
        iter++;

    }
    return costo;

}