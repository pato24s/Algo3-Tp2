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
			cout << "Instancia;V;E;K;Tiempo;" << endl;
    		while(1){

        	 	cin >> V >> E;  //Proceso la primera linea
        	 	if(V == -1){  //Si es la linea del -1 -1 termino
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
    		    auto start = ya();
				int sol = ejercicio1(grafo, src - 1, dst - 1, k);
				auto stop = ya();
    		    cout << j + 1 << ";"<< V << ";" << E << ";" << k << ";" << chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << endl;
    		    j++;
    		}
        	break;
    	

    	case 2:
			cout << "Instancia;V;E;Pmx;Tiempo;" << endl;
  			while(1){
  			    cin >> V >> E;  //Proceso la primera linea

			    if(V == -1){     //Si es la linea del -1 -1 chau
			        break;
			    }
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
			    auto start = ya();
				int sol = ejercicio2(grafo, maxPeaje);
				auto stop = ya();
			    cout << j + 1 << ";"<< V << ";" << E << ";" << maxPeaje << ";" << chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << endl;
			    j++;
   			}
    	    break;
	   		
		case 3:
			cout << "Instancia;V;E;pctConst;Tiempo;" << endl;
			while(1){
			    cin >> V;	    //Proceso la primera linea
			    if(V == -1){		//Si es la linea del -1 -1 termino
			        break;
			    }
			    GrafoConPeso grafo(V);
			    int c1;
			    int c2;
			    bool construida;
			    int peso;
			    float cantConst=0;
			   	float pctConst;
			    E = (V * (V - 1)) / 2;
			    for (int i = 0; i < E; ++i)
			    {
			        cin >> c1 >> c2 >> construida >> peso;
			        if(construida){
			            peso = peso * (-1);
			            cantConst++;
			        }
			      	//Se resta 1 a c1 y c2 porque indexamos desde 0
			      	grafo.agregarEje(c1 - 1 , c2 - 1, peso);
			    }

			    //Se resta 1 a src y dst porque indexamos desde 0
			    auto start = ya();
				int sol = ejercicio3(grafo);
				auto stop = ya();
				pctConst = (cantConst/E)*100;
			    cout << j + 1 << ";"<< V << ";" << E << ";" << pctConst << ";" << chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << endl;
			    j++;
			 }
			break;
		
   		default:
   			cout << "Error. Ejercicio desconocido. Opciones: 1, 2 o 3." << endl;
	}

	return 0;
}
