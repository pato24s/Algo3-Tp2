#include "grafos.h"

//Metodos de GrafoConPeso


GrafoConPeso::GrafoConPeso(int Ve){
	vector<vector<int> > mat;
	for (int i = 0; i < Ve; i++){
		vector<int> fila;

		for(int j = 0 ; j < Ve; j++){
			fila.push_back(0);
		}
		mat.push_back(fila);
	}
	
	V = Ve;
	E = 0;
	matriz = mat;
}

void GrafoConPeso::agregarEje(int u, int v, int peso){
	matriz[u][v] = peso;
	matriz[v][u] = peso;
	E++;
}

//Metodos de GrafoConPremium

GrafoConPremium::GrafoConPremium(int V){
	vector<vector<pair<int, bool> > > mat;
	for (int i = 0; i < Ve; i++){
		vector<pair<int, bool> > fila;

		pair<int, bool> pNull = make_pair(0,false);
		
		for(int j = 0; j < Ve; j++){
			fila.push_back(pNull);
		}
		
		mat.push_back(fila);
	}
	
	V = Ve;
	E = 0;
	matriz = mat;
}

void GrafoConPremium::agregarEje(int u, int v, int peso, bool premium){
	pair<int, bool> aux = make_pair(peso,premium);
	matriz[u][v] = aux;
	matriz[v][u] = aux;
	E++;
}