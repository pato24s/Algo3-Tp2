#include "metodos.h"	//Metodos de camino minimo

using namespace std;

int main(){   
    cout << "Procesando instancias del ejercicio 1" << endl;
    int j = 0;
    while(1){
        int V;
        int E;
        cin >> V >> E;	//Proceso la primera linea
        if(V == -1){	//Si es la linea del -1 -1 termino
            break;
        }		
        int src;
        int dst;
        int k;
        cin >> src >> dst >> k;

        GrafoConPremium grafo(V);
        int c1;
        int c2;
        bool premium;
        int peso;
        for (int i = 0; i < E; ++i)
        {
            cin >> c1 >> c2 >> premium >> peso;
          	//Se resta 1 a c1 y c2 porque indexamos desde 0
          	grafo.agregarEje(c1 - 1 , c2 - 1, peso, premium);
        }

        //Se resta 1 a src y dst porque indexamos desde 0
        cout<<"Solucion de la instancia " << j + 1 << ": "<< ejercicio1(grafo, src - 1, dst - 1, k) << endl;
        j++;
    }

    return 0;
}