#include <chrono>
#include <fstream>
#include <string>
#include "metodos.h"


#define ya chrono::high_resolution_clock::now


using namespace std;

/* ./tiempo.cpp N°_ejer < entrada.txt
 * imprime por pantalla en formato csv el tiempo que tarda en resolver
 * cada instancia del archivo entrada.txt (en ns).
 */


int main(int argc, char* argv[]){
	
	int ejer = atoi(argv[2]);

	//Imprimo header
	cout << "Instancia;V;E;Tiempo;" << endl;
	
	switch(ejer){
		case 1:
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
    		    auto start = ya();
				    int sol = ejercicio1(grafo, src - 1, dst - 1, k);
				    auto stop = ya();
    		    cout << j + 1 << ";"<< V << ";" << E << ";" << chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << endl;
    		    j++;
    		}
    		break;

    	case 2:
   			int j = 0;
   			while(1){
   			    int V;
   			    int E;
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
   			    cout << j + 1 << ";"<< V << ";" << E << ";" << chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << endl;
   			    j++;
   			}
   			break;

   		case 3:
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
   			    auto start = ya();
				    int sol = ejercicio3(grafo);
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
