#include <stdio.h>
#include <limits.h>
  
#define V 9
  
//Busca el vertice de minima distancia de los vertices no visitados
int minimaDistancia(int dist[], bool visitados[])
{
   // Al principio las distancias tentativas valen infinito
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (visitados[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// printea la solucion
int printSolucion(int dist[], int n)
{
   printf("Vertice   Distancia desde origen\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
  
//Dijkstra usando la matriz de adyacencia
void dijkstra(int graph[V][V], int src)
{
     int dist[V];     // Arreglo de las distancias minimas. dis[i] guarda la distancia minima desde el origen
  
     bool visitados[V]; // Arreglo de vertices visitados
  
     // Todas las distancias al principio son infinitas y no visite ninguno
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visitados[i] = false;
  
     // La distancia del origen es 0
     dist[src] = 0;
  
     // En este ciclo encuentra el camino mas corto de todos los nodos
     for (int count = 0; count < V-1; count++)
     {
       // Toma el vertice no visitado que tiene la minima distancia. u vale src en la primera iteracion.
       int u = minimaDistancia(dist, visitados);
  
       // Marcarlo como visitado
       visitados[u] = true;
  
       // Actualizar las distancias de los vertices adyacentes al actual procesado.
       for (int v = 0; v < V; v++)

        // Actualizar las distancias si no lo visite y hay un camino mas corto
         if (!visitados[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     printSolucion(dist, V);
}
  
int main()
{
 
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}