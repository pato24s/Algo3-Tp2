#include "metodos.h"	//Metodos de camino minimo

using namespace std;

int main(){   
    cout << "Ejercicio 1!" << endl;
    cout << "Ingrese un numero" << endl;
    int j = 0;
    while(1){
        int V;
        int E;
        cin >> V >> E;	//proceso la primer linea
        if(V == -1)		//si es la linea del -1 -1 termino
            break;
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

        for (int i = 0; i < V; ++i)
        {
        	for (int j = 0; j < V; ++j)
        	{
        		cout << "(" << grafo.peso(i, j) << "," << grafo.esPremium(i, j) <<")";
        		if(j != V - 1){
        			cout << ", ";
        		}
        	}
        	cout << endl;
        }
        cout << endl;
        // cout<<grafo.E<<endl;
        // cout<<"src: "<<src<<" dst: "<<dst<<" k: "<<k<<endl;
        //Se resta 1 a src y dst porque indexamos desde 0
        cout<<"salida instancia " << j << ": "<< ejercicio1(grafo, src - 1, dst - 1, k) << endl;
        j++;
    }

    return 0;
}