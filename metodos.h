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

bool BellmanFord(struct Graph* graph, int k);

int ejercicio2(struct Graph* graph, int maxPeaje);