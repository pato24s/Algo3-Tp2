#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include <utility>
#include "grafos.h"		//Clases de grafos

/* ------------------ Constantes y defines ------------------ */


/* ------------------ Ejer 1 ------------------------------------- */
int proximoNodo(pair<int,int> dist[], bool visitados[], int V);

int ejercicio1(GrafoConPremium &grafo, int src, int dest, int k);

/* ------------------ Ejer 2 ------------------------------------- */

bool BellmanFord(DigrafoConPeso &grafo, int k);

int ejercicio2(DigrafoConPeso &grafo, int maxPeaje);

/* ------------------ Ejer 3 ------------------------------------- */


void kruskal_init(int n);

int kruskal_find(int x);

void kruskal_uni(int x, int y);


int ejercicio3(GrafoConPeso &grafo);