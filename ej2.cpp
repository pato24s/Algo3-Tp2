#include "metodos.h"    //Metodos de camino minimo

using namespace std;


// Driver program to test above functions
int main(){
    cout << "Procesando instancias del ejercicio 2" << endl;
    int j = 0;
    while(1){
        int V;
        int E;
        cin >> V >> E;  //Proceso la primera linea

        if(V == -1){     //Si es la linea del -1 -1 chau
            break;
        }
        DigrafoConPeso grafo(V + 1); //Creo digrafo con V vertices y el nodo fantasma
        int c1;
        int c2;
        int p;
        int maxPeaje = -1000;        //Se asume que ninguna arista tiene peso menor a -1000.
        for (int i = 0; i < E; ++i){
            cin >> c1 >> c2 >> p;
            if(p > maxPeaje){
                maxPeaje = p;
            }
            Eje nuevaArista(c1 - 1, c2 - 1, p);
            grafo.agregarEje(nuevaArista);
        }
        for (int i = 0; i < V ; ++i){
            Eje aristaFantasma(V, i, 0);
            grafo.agregarEje(aristaFantasma);
        }
        cout<< "Solucion de la instancia " << j + 1 << ": " << ejercicio2(grafo, maxPeaje) << endl;
        j++;
    }

    return 0;
}