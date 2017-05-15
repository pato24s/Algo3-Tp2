#include "metodos.h"	//Metodos de camino minimo

using namespace std;

int main(){   
    cout << "Procesando instancias del ejercicio 3" << endl;
    int j = 0;
    while(1){
        int V;
        cin >> V;	    //Proceso la primera linea
        if(V == -1){		//Si es la linea del -1 -1 termino
            break;
        }
        GrafoConPeso grafo(V);
        int c1;
        int c2;
        bool construida;
        int peso;
        int E = (V * (V - 1)) / 2;
        for (int i = 0; i < E; ++i)
        {
            cin >> c1 >> c2 >> construida >> peso;
            if(construida){
                peso = peso * (-1);
            }
          	//Se resta 1 a c1 y c2 porque indexamos desde 0
          	grafo.agregarEje(c1 - 1 , c2 - 1, peso);
        }

        //Se resta 1 a src y dst porque indexamos desde 0
        cout<<"Solucion de la instancia " << j + 1 << ": "<< ejercicio3(grafo) << endl;
        j++;
    }

    return 0;
}