#include <vector>
#include <set>

using namespace std;

class Eje{	//Para ejercicio 3
	public:
		//Varios constructores para distintos tipos de ejes (con o sin peso, construida o no)
		Eje(int n1, int n2, int p, int c): u(n1), v(n2), peso(p), construida(c) {}
		Eje(int n1, int n2, int p): u(n1), v(n2), peso(p), construida(-1) {}
		
		//Getters
		int dameU() const {return u;}
		int dameV() const {return v;}
		int damePeso() const {return peso;}
		int dameConstruida() const {return construida;}

		//Setters
		int setU(int nodo) {u = nodo;}
		int setV(int nodo) {v = nodo;}
		int setPeso(int p) {peso = p;}
		int setConstruida(int c) {construida = c;}

		bool operator<(const Eje& ej) const{
   			return peso < ej.peso || u < ej.u || v < ej.v;
		}

	private:
		int u;
		int v;
		int peso;
		int construida;


};

//Ejercicio 1. Grafo no dirigido con peso en los ejes y un booleano que indica si la ruta es o no premium
class GrafoConPremium{
	public:
		//Crea un grafo vacio
		GrafoConPremium() {};
		
		//Crea un grafo con Ve vertices disconexos
		GrafoConPremium(int Ve);

		~GrafoConPremium() {};

		//Agrega un eje con peso entre u y v al grafo, y si es o no premium
		void agregarEje(int u, int v, int peso, bool premium);

		//Devuelve true si u y v estan conectados y false en caso contrario
		bool conectados(int u, int v);

		//Requiere que conectados(u, v) sea true. Devuelve el peso de la conexion entre u y v. 
		int peso(int u, int v);

		//Requiere que conectados(u, v) sea true. Devuelve 1 si la conexion entre u y v es un premium y 0 si no. 
		int esPremium(int u, int v);

		//Getters
		int dameV() {return V;}
		int dameE() {return E;}

	private:
		vector<vector<pair<int, bool> > > matriz;
		int V;
		int E;

};

//Ejercicio 2. Grafo dirigido con pesos.
class DigrafoConPeso{
	public:
		//Crea un grafo vacio
		DigrafoConPeso() {};
		
		//Crea un grafo con Ve vertices disconexos
		DigrafoConPeso(int Ve);

		~DigrafoConPeso() {};

		//Agrega un eje con peso entre u y v al grafo
		void agregarEje(int u, int v, int peso);

		//Requiere que conectados(u, v) sea true. Devuelve el peso de la conexion entre u y v. 
		int peso(int u, int v);

		//Devuelve un iterador al inicio de la lista de aristas. Puede modificar elementos.
		set<Eje>::iterator aristasInicio();

		//Devuelve un iterador al final de la lista de aristas. Puede modificar elementos.
		set<Eje>::iterator aristasFin();

		//Getters
		int dameV() {return V;}
		int dameE() {return E;}

	private:
		set<Eje> aristas;
		int V;
		int E;

};

//Ejercicio 3. Grafo no dirigido con pesos.
class GrafoConPeso{
	public:
		//Crea un grafo vacio
		GrafoConPeso() {};
		
		//Crea un grafo con Ve vertices disconexos
		GrafoConPeso(int Ve);

		~GrafoConPeso() {};

		//Agrega un eje con peso entre u y v al grafo
		void agregarEje(Eje e);

		//Requiere que conectados(u, v) sea true. Devuelve el peso de la conexion entre u y v. 
		int peso(int u, int v);

		//Devuelve un iterador al inicio de la lista de aristas. Puede modificar elementos.
		set<Eje>::iterator aristasInicio();

		//Devuelve un iterador al final de la lista de aristas. Puede modificar elementos.
		set<Eje>::iterator aristasFin();

		//Getters
		int dameV() {return V;}
		int dameE() {return E;}

	private:
		set<Eje> aristas;
		int V;
		int E;

};