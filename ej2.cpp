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
            grafo.agregarEje(c1, c2, p);
        }
        cout<< "Solucion de la entrada " << j << ": " << ejercicio2(grafo, maxPeaje) << endl;
        j++;
    }

    return 0;
}