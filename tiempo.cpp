#include <chrono>
#include <fstream>
#include <string>
#include "metodos.h"
#include <iostream>

#define ya chrono::high_resolution_clock::now


using namespace std;

/* ./tiempo.cpp N°_ejer < entrada.txt
 * imprime por pantalla en formato csv el tiempo que tarda en resolver
 * cada instancia del archivo entrada.txt (en ns).
 */


int main(int argc, char* argv[]){
	int ejer = atoi(argv[1]);

	//Imprimo header
	int j = 0;
	int V;
	int E;
	switch(ejer){
  		case 1:
			cout << "Instancia;V;E;K;CantPrem;PctK;Sol;Tiempo;" << endl;
    		while(1){

        	 	cin >> V >> E;  //Proceso la primera linea
        	 	if(V == -1){  	//Si es la linea del -1 -1 termino
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
        	 	int cantPrem = 0;
        	 	float pctK = 0;
        	 	for (int i = 0; i < E; ++i)
        	 	{
        	 	    cin >> c1 >> c2 >> premium >> peso;
        	 	    if(premium){
        	 	    	cantPrem++;
        	 	    }
        	 	    //Se resta 1 a c1 y c2 porque indexamos desde 0
        	 	    grafo.agregarEje(c1 - 1 , c2 - 1, peso, premium);
        	 	}
				if(!cantPrem == 0.0){
					pctK = (k / (float) cantPrem) * 100;
				} else {
					pctK = 0;
				}
    		    //Se resta 1 a src y dst porque indexamos desde 0
    		    auto start = ya();
				int sol = ejercicio1(grafo, src - 1, dst - 1, k);
				auto stop = ya();
    		    cout << j + 1 << ";"<< V << ";" << E << ";" << k << ";" << cantPrem << ";" << pctK << ";" << sol << ";" << chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << endl;
    		    j++;
    		}
        	break;
    	

    	case 2:
			cout << "Instancia;V;E;MaxPeaje;Tiempo;" << endl;
  			while(1){
  			    cin >> V >> E;  //Proceso la primera linea

			    if(V == -1){    //Si es la linea del -1 -1 chau
			        break;
			    }
			    DigrafoConPeso grafo(V + 1); //Creo digrafo con V vertices y el nodo fantasma
			    int c1;
			    int c2;
			    int p;
			    int maxPeaje = -1000;
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
			    auto start = ya();
				int sol = ejercicio2(grafo, maxPeaje);
				auto stop = ya();
			    cout << j + 1 << ";"<< V << ";" << E << ";" << maxPeaje << ";" << chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << endl;
			    j++;
   			}
    	    break;
	   		
		case 3:

			cout << "Instancia;V;E;Tiempo;" << endl;

			while(1){
			    cin >> V;	    //Proceso la primera linea
			    if(V == -1){	//Si es la linea del -1 -1 termino
			        break;
			    }
			    GrafoConPeso grafo(V);
			    int c1;
			    int c2;
			    int construida;
			    int peso;
			    E = (V * (V - 1)) / 2;
			    for (int i = 0; i < E; ++i){
			        cin >> c1 >> c2 >> construida >> peso;
			      	//Se resta 1 a c1 y c2 porque indexamos desde 0
			      	Eje nuevaArista(c1 - 1, c2 - 1, peso, construida);
           			grafo.agregarEje(nuevaArista);
			    }

			    //Se resta 1 a src y dst porque indexamos desde 0
			    auto start = ya();
				int sol = ejercicio3(grafo, true);
				auto stop = ya();
			    
			    cout << j + 1 << ";"<< V << ";" << E << ";" << chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << endl;
			    j++;
			 }
			break;
		
   		default:
   			cout << "Error. Ejercicio desconocido. Opciones: 1, 2 o 3." << endl;
	}

	return 0;
}
