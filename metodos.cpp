#include "metodos.h"	//Metodos de camino minimo

using namespace std;

/* ------------------ Ejer 1 ------------------ */

pair<int,int> proximoNodo(int filas, int cols, vector<vector<pair<int, int> > > &dist, vector<vector<bool> > &visitados){
	int min = INT_MAX;
    pair<int, int> min_ij;

    for (int i = 0; i < filas + 1; i++){
        for (int j = 0; j < cols; j++){
            if(visitados[i][j] == false && dist[i][j].first <= min){
            	pair<int, int> indices(i,j);
                min = dist[i][j].first;
                min_ij = indices;
            }    
        }
    }
    return min_ij;
}

int ejercicio1(GrafoConPremium &grafo, int src, int dest, int k){
    bool termine = false;
    int V = grafo.dameV();

	pair<int, int> tuplaCero(0, 0);
    pair<int, int> tuplaInf(INT_MAX, 0);
    vector<vector<pair<int, int> > > dist(k + 1, vector<pair<int, int> >(V, tuplaInf));
    vector<vector<bool> > visitados(k + 1, vector<bool>(V, false));
	dist[0][src] = tuplaCero;
	pair<int,int> elegido;
    
    //DEBUG
    int c = 0;
    cout << "El origen es " << src + 1 << " y el destino es " << dest + 1 << endl; 
    for (int count = 0; count < (V*(k + 1)) - 1; count++){
        if(termine){
           	break;
        }
        elegido = proximoNodo(k, V, dist, visitados);
        //DEBUG
        cout << "elegido: (" << elegido.first << "," << elegido.second + 1 << ")" << endl;
        int nivel = elegido.first;
        int nodo = elegido.second;

        //DEBUG
        if(nivel == dist[nivel][nodo].second){
        	c++;
        	cout << "Son iguales. C = " << c << endl;
        }

        int dist_elegido = dist[nivel][nodo].first;

        visitados[nivel][nodo] = true;
    
        
        for (int ik = 0; ik < k + 1; ik++){
            if(termine){
            	break;
            }
            for (int v = 0; v < V; v++){
                if(!visitados[ik][v] && ik == nivel && grafo.conectados(nodo,v) && dist_elegido != INT_MAX && 
                		dist_elegido + grafo.peso(nodo,v) < dist[ik][v].first){
                    
                    pair<int, int> tuplaCamino(dist_elegido + grafo.peso(nodo, v),
                    	 nivel + grafo.esPremium(nodo,v));

                    int nuevoNivel = nivel + grafo.esPremium(nodo,v);
                    if(nuevoNivel <= k){
                        dist[nuevoNivel][v] = tuplaCamino;
                        // cout<<"v: "<<v<<" ,ik: "<<ik<<endl;
                        cout<<" actualizando a: (" << nuevoNivel << "," << v + 1 << ") con valores: (" << tuplaCamino.first << "," << tuplaCamino.second <<")" << endl;
                        if(v == dest){
                        	
                            termine = true;
                        	break;
                        }
                    }
                }
            }
        }
        cout << " Count = " << count << endl;
    }

    int result = INT_MAX;
    for(int i = 0; i < k + 1; i++){
        if(dist[i][dest].first < result){
            result = dist[i][dest].first;
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
bool BellmanFord(DigrafoConPeso &g, int k)
{
    int V = g.dameV();
    int E = g.dameE();
    int dist[V];
 
    //Inicializo distancias a todos los nodos como infinito 
    for (int i = 0; i < V; i++){
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
 
    //Relajo |v| - 1 veces todas las aristas para conseguir los caminos minimos.
    for (int i = 1; i <= V-1; i++)
    {
        for (set<Eje>::iterator it = g.aristasInicio(); it != g.aristasFin(); ++it)
        {
            int u = (*it).dameU();
            int v = (*it).dameV();
            int weight = (*it).damePeso() - k;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
 
    //Busco ciclos negativos con una iteracion de relajacion mas
    for (set<Eje>::iterator it = g.aristasInicio(); it != g.aristasFin(); ++it)
    {
        int u = (*it).dameU();
        int v = (*it).dameV();
        int weight = (*it).damePeso() - k;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]){
            return true;
        }
    }
    
    return false;
}
 


int ejercicio2(DigrafoConPeso &grafo, int maxPeaje){
    int reduccion;
    
    bool perdemosPlata;
    int init = 0;
    int fin = maxPeaje;
    int mid = (fin + init) / 2;
    
    //Busqueda binaria de la maxima reduccion
    while(init <= fin){
        reduccion = mid;
        
        perdemosPlata = BellmanFord(grafo, reduccion);

        if(perdemosPlata){
        //Si perdemos plata solucion esta entre init y mid (hay que reducir menos el precio)
            fin = mid - 1;
        }else{
            //Si no perdemos plata podemos aumentar la reduccion 
            //La solucion esta entre entre mid y fin
            init = mid + 1;
        }
        mid = (init + fin) / 2;

    }  
    return reduccion;
}

/* ------------------ Ejer 3 ------------------ */

int altura[1000000];
int padre[1000000];



void kruskal_init(int n) {
    for (int i = 1; i < n; ++i){
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
    }else{
        padre[y] = x;
    }

    if(altura[x] == altura[y]){
        altura[x] = altura[x] + 1;
    }
}


//Kruskal modificado
int ejercicio3(GrafoConPeso &g){
    int costo = 0;
    int Ve = g.dameV();

    //DEBUG
    cout << "lista de aristas: " << endl;
    for (std::set<Eje>::iterator it = g.aristasInicio(); it != g.aristasFin(); ++it){
        int u = (*it).dameU();
        int v = (*it).dameV();
        int weight = (*it).damePeso();
        cout << "(" << u + 1 << "," << v + 1 << ") p: " << weight << endl;
    }
    
    vector<pair<int, int> > solucion_ejes;
    kruskal_init(Ve);

    set<Eje>::iterator iter = g.aristasInicio();
    
    for (int j = 0; j < g.dameE(); ++j){
        int eje_u = (*iter).dameU();
        int eje_v = (*iter).dameV();
        int eje_p = (*iter).damePeso();

        if(kruskal_find(eje_u) != kruskal_find(eje_v)){
            cout << "sirve eje: (" << eje_u + 1 << " " << eje_v + 1 << ")" << endl;
            //Agrego el eje a la solucion
            pair<int,int> ejeValido(eje_u, eje_v);
            solucion_ejes.push_back(ejeValido);
            
            //Si el peso era negativo no agrego el costo (ya la tengo construida)
            if(eje_p > 0){
                costo += eje_p;
            }

            //Uno las componentes
            kruskal_uni(eje_u, eje_v);


        }else{
            //No sirve la arista, si estaba construida tengo que agregar costo de destruccion
            if(eje_p < 0){
                costo += (eje_p) * (-1);
            }
        }
        iter++;

    }
    //Agregar flag
    cout << costo << " " << solucion_ejes.size() << endl;
    return costo;
}