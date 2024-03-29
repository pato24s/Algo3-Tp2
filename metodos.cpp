#include "metodos.h"	//Metodos de camino minimo

using namespace std;

/* ------------------ Ejer 1 ------------------ */

pair<int,int> proximoNodo(int filas, int cols, vector<vector<int> > &dist, vector<vector<bool> > &visitados){
	int min = INT_MAX;
    pair<int, int> min_ij;

    for (int i = 0; i < filas + 1; i++){
        for (int j = 0; j < cols; j++){
            if(visitados[i][j] == false && dist[i][j] <= min){
            	pair<int, int> indices(i,j);
                min = dist[i][j];
                min_ij = indices;
            }    
        }
    }
    return min_ij;
}

int ejercicio1(GrafoConPremium &grafo, int src, int dest, int k){
    bool termine = false;
    int V = grafo.dameV();

    //Matrices de distancia y visitados
    vector<vector<int> > dist(k + 1, vector<int>(V, INT_MAX));
    vector<vector<bool> > visitados(k + 1, vector<bool>(V, false));
	dist[0][src] = 0;
	pair<int, int> elegido;
    

    for (int count = 0; count < (V*(k + 1)) - 1; count++){
        if(termine){
           	break;
        }
        elegido = proximoNodo(k, V, dist, visitados);
        int nivel = elegido.first;
        int nodo = elegido.second;

        int dist_elegido = dist[nivel][nodo];

        visitados[nivel][nodo] = true;
    
        for (int v = 0; v < V; v++){
            int nuevaDist = dist_elegido + grafo.peso(nodo, v);

            if(!visitados[nivel][v] && grafo.conectados(nodo, v) && dist_elegido != INT_MAX && 
            		nuevaDist < dist[nivel][v]){
                
                int nuevoNivel = nivel + grafo.esPremium(nodo, v);

                if(nuevoNivel <= k){
                    dist[nuevoNivel][v] = nuevaDist;
                    //Si ya llegue al destino, termino los ciclos
                    if(v == dest){
                        termine = true;
                    	break;
                    }
                }
            }
        }
    }

    //Buscamos el resultado final
    int result = INT_MAX;
    for(int i = 0; i < k + 1; i++){
        if(dist[i][dest] < result){
            result = dist[i][dest];
        }
    }

    if(result == INT_MAX){
        return -1;
    }
    return result;

}


/* ------------------ Ejer 2 ------------------ */

 
//Calcula la distancia del vertice 1 a todos los otros. Nos interesa checkear que
//luego de relajar |V| - 1 veces las aristas, no queden ciclos negativos. 
bool BellmanFord(DigrafoConPeso &grafo, int k)
{
    int V = grafo.dameV();
    int E = grafo.dameE();
    int dist[V];
 
    //Inicializo distancias a todos los nodos como infinito 
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
    }
    dist[V-1] = 0;
    
    //Relajo |v| - 1 veces todas las aristas para conseguir los caminos minimos.
    for (int i = 1; i <= V-1; i++)
    {
        for (set<Eje>::iterator it = grafo.aristasInicio(); it != grafo.aristasFin(); ++it)
        {
            int u = (*it).dameU();
            int v = (*it).dameV();
            int weight = (*it).damePeso() - k;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }
 
    //Busco ciclos negativos con una iteracion de relajacion mas
    int count=0;
    for (set<Eje>::iterator it = grafo.aristasInicio(); it != grafo.aristasFin(); ++it)
    {
        int u = (*it).dameU();
        int v = (*it).dameV();
        int weight = (*it).damePeso() - k;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
            return true;
        }
        count++;
    }
    return false;
}
 


int ejercicio2(DigrafoConPeso &grafo, int maxPeaje){
    int reduccion;
    
    bool perdemosPlata;
    int comienzo = 0;
    int fin = maxPeaje;
    int mid = (fin + comienzo) / 2;
    
    //Busqueda binaria de la maxima reduccion
    while(comienzo + 1 != fin){
        reduccion = mid;
        
        perdemosPlata = BellmanFord(grafo, reduccion);

        if(perdemosPlata){
            //Si perdemos plata solucion esta entre comienzo y mid (hay que reducir menos el precio)
            fin = mid;
        }else{
            //Si no perdemos plata podemos aumentar la reduccion 
            //La solucion esta entre entre mid y fin
            comienzo = mid;
        }
        mid = (comienzo + fin) / 2;

    }  
    //Vemos si perdimos o no plata en la ultima iteracion
    bool pierdePlataFin = BellmanFord(grafo, fin);
    if(!pierdePlataFin){
        return fin;
    }else{
        return comienzo;
    }
}

/* ------------------ Ejer 3 ------------------ */

int altura[1000000];
int padre[1000000];



void kruskal_init(int n) {
    for (int i = 0; i < n; ++i){
        altura[i] = 1;
        padre[i] = i;
    }    
}

int kruskal_find(int x) {
    if(padre[x] != x){
        padre[x] = kruskal_find(padre[x]);
    }
    return padre[x];
}

void kruskal_uni(int x, int y) {
    x = kruskal_find(x);
    y = kruskal_find(y);
    if(altura[x] < altura[y]){
        padre[x] = y;
    } else {
        padre[y] = x;
    }

    if(altura[x] == altura[y]){
        altura[x] = altura[x] + 1;
    }
}

//Struct para poder ordenar las aristas de menor a mayor en el conjunto.
struct pesoComp {
	
	bool operator() (const Eje& lhs, const Eje& rhs) const{
		int e1Peso = lhs.damePeso();
		int e1U = lhs.dameU();
		int e1V = lhs.dameV();
		int e2Peso = rhs.damePeso();
		int e2U = rhs.dameU();
		int e2V = rhs.dameV();
		bool pesoE1Menor = e1Peso < e2Peso;
		bool pesosIguales = e1Peso == e2Peso;
		bool uE1Menor = e1U < e2U;
		bool usIguales = e1U == e2U;

		return (pesoE1Menor) || (pesosIguales && uE1Menor) || (pesosIguales && usIguales && e1V < e2V);
	}
};

//Kruskal modificado. Altera el peso de las aristas construidas del grafo. Si modo_tiempo es true no se imprime
//el vector solucion por pantalla.
int ejercicio3(GrafoConPeso &grafo, bool modo_tiempo){
    
	//Almacena las aristas del grafo ordenadas de menor a mayor peso
    set<Eje, pesoComp> aristasOrdenadas;
    
    //Ordena las aristas del grafo de menor a mayor peso.
    for(set<Eje>::iterator it = grafo.aristasInicio(); it != grafo.aristasFin(); it++){
    	Eje arista = *it;
    	//Si esta construida, cambiamos el signo del peso.
    	if(arista.dameConstruida()){
    		arista.setPeso(arista.damePeso() * (-1));
    	}
    	aristasOrdenadas.insert(arista);
    }

    int Ve = grafo.dameV();

    //Guarda la solucion
    int costo = 0;
    vector<pair<int, int> > solucion_ejes;
    
    kruskal_init(Ve);
    
    for (set<Eje>::iterator iter = aristasOrdenadas.begin(); iter != aristasOrdenadas.end(); iter++){
        int eje_u = (*iter).dameU();
        int eje_v = (*iter).dameV();
        int eje_p = (*iter).damePeso();

        if(kruskal_find(eje_u) != kruskal_find(eje_v)){
            //Agrego el eje a la solucion. Sumamos 1 porque indexamos desde 0.
            pair<int,int> ejeValido(eje_u + 1, eje_v + 1);
            solucion_ejes.push_back(ejeValido);
            
            //Si el peso era negativo, no agrego el costo (ya la tengo construida)
            if(eje_p > 0){
                costo += eje_p;
            }

            //Uno las componentes
            kruskal_uni(eje_u, eje_v);


        } else {
            //No sirve la arista. Si estaba construida, tengo que agregar costo de destruccion
            if(eje_p < 0){
                costo += (eje_p) * (-1);
            }
        }
    }
    //Imprime o no la solucion
    if(!modo_tiempo){
        cout << costo << " " << solucion_ejes.size() << " ";
        for(int i = 0; i < solucion_ejes.size(); i++){
            cout << "(" <<  solucion_ejes[i].first << ", " << solucion_ejes[i].second << ") " ;
        }
        cout << endl;
    }
    return costo;
}