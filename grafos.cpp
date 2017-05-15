#include "grafos.h"

//Metodos de Grafo

Grafo::Grafo(int Ve){
	for (int i = 0; i < Ve; i++){
		vector<int> fila;

		for(int j = 0 ; j < Ve; j++){
			fila.push_back(0);
		}
		matriz.push_back(fila);
	}
	
	V = Ve;
	E = 0;
	
}

void Grafo::agregarEje(int u, int v){
	//Si u o v son mas grandes que V, estoy agregando vertices al grafo ademas de aristas. Agrando la matriz
	if(u > V){
		matriz.resize(u);
		for(int i = 0; i < matriz.size(); i++){
			matriz[i].resize(u);
		}
	} else if(v > V){
		matriz.resize(v);
		for(int i = 0; i < matriz.size(); i++){
			matriz[i].resize(v);
		}
	}
	matriz[u][v] = 1;
	matriz[v][u] = 1;
	E++;
}

bool Grafo::conectados(int u, int v){
	if(matriz[u][v]){
		return true;
	}
	return false;
}


//Metodos de GrafoConPremium

GrafoConPremium::GrafoConPremium(int Ve){
	vector<vector<pair<int, bool> > > mat;
	for (int i = 0; i < Ve; i++){
		vector<pair<int, bool> > fila;

		pair<int, bool> pNull = make_pair(0,false);
		
		for(int j = 0; j < Ve; j++){
			fila.push_back(pNull);
		}
		
		matriz.push_back(fila);
	}
	
	V = Ve;
	E = 0;
	
}

void GrafoConPremium::agregarEje(int u, int v, int peso, bool premium){
	//Si u o v son mas grandes que V, estoy agregando vertices al grafo ademas de aristas. Agrando la matriz
	if(u > V){
		matriz.resize(u);
		for(int i = 0; i < matriz.size(); i++){
			matriz[i].resize(u);
		}
	} else if(v > V){
		matriz.resize(v);
		for(int i = 0; i < matriz.size(); i++){
			matriz[i].resize(v);
		}
	}

	pair<int, bool> aux = make_pair(peso,premium);
	matriz[u][v] = aux;
	matriz[v][u] = aux;
	E++;
}

bool GrafoConPremium::conectados(int u, int v){
	if(matriz[u][v].first){
		return true;
	}
	return false;
}

int GrafoConPremium::peso(int u, int v){
	return matriz[u][v].first;
}

int GrafoConPremium::esPremium(int u, int v){
	if(matriz[u][v].second){
		return 1;
	}
	return 0;
}

//Metodos de DigrafoConPeso

DigrafoConPeso::DigrafoConPeso(int Ve){
	V = Ve;
	E = 0;
}

void DigrafoConPeso::agregarEje(int u, int v, int peso){
	Eje nuevaArista(u, v, peso);
	aristas.insert(nuevaArista);

	E = aristas.size();

}

int DigrafoConPeso::peso(int u, int v){
	return matriz[u][v];
}

set<Eje>::iterator DigrafoConPeso::aristasInicio(){
	return aristas.begin();
}

set<Eje>::iterator DigrafoConPeso::aristasFin(){
	return aristas.end();
}

//Metodos de GrafoConPeso

GrafoConPeso::GrafoConPeso(int Ve){
	V = Ve;
	E = 0;
}

void GrafoConPeso::agregarEje(int u, int v, int peso){
	Eje nuevaArista(u, v, peso);
	aristas.insert(nuevaArista);

	E = aristas.size();
}

int GrafoConPeso::peso(int u, int v){
	return matriz[u][v];
}


set<Eje>::iterator GrafoConPeso::aristasInicio(){
	return aristas.begin();
}

set<Eje>::iterator GrafoConPeso::aristasFin(){
	return aristas.end();
}

