#include "grafos.h"

//Metodos de Grafo

Grafo::Grafo(int Ve){
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
	matriz[u][v] = peso;
	matriz[v][u] = peso;
	E++;
}

//Metodos de DigrafoConPeso

DigrafoConPeso::DigrafoConPeso(int Ve){
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

void DigrafoConPeso::agregarEje(int u, int v, int peso){
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
	matriz[u][v] = peso;
	E++;
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
		
		mat.push_back(fila);
	}
	
	V = Ve;
	E = 0;
	matriz = mat;
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