#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include "grafos.h"     //Clases de grafos
#include "metodos.h"    //Metodos de camino minimo

using namespace std;


// Driver program to test above functions
int main()
{   int j = 0;
    while(1){
        int V;
        int E;
        cin >> V >> E;//proceso la primer linea
        if(V == -1)//si es la linea del -1 -1 chau
            break;

        DigrafoConPeso grafo(V); //Creo digrafo con V vertices
        int c1;
        int c2;
        int p;
        int maxPeaje = -1000;
        for (int i = 0; i < E; ++i)
        {
            cin >> c1 >> c2 >> p;
            if(p > maxPeaje)
                maxPeaje = p;
            grafo.agregarArista(c1, c2, p);
        }
        cout<< "Solucion de la entrada " << j << ": " << ejercicio2(graph, maxPeaje) << endl;
        j++;
    }

    return 0;
}