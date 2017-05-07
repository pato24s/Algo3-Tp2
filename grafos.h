#include <vector>


class eje{
	public:
		//Varios constructores para distintos tipos de ejes (con o sin peso, premium o no premium)
		eje(int n1, int n2, int p, int prem): u(n1), v(n2), peso(p), premium(prem) {};
		eje(int n1, int n2, int p): u(n1), v(n2), peso(p), premium(-1) {};
		eje(int n1, int n2): u(n1), v(n2), peso(0), premium(-1) {};
		
		//Getters
		int u() {return u};
		int v() {return v};
		int peso() {return peso};
		int premium() {return premium};

		//Setters
		int setU(int nodo) {u = nodo};
		int setV(int nodo) {v = nodo};
		int setPeso(int p) {peso = p};
		int setPremium(int prem) {premium = prem};

	private:

		int u;
		int v;
		int peso;
		int premium;
};

class Grafo{
	public:

		Grafo() {};
		Grafo(int Ve);
		~Grafo() {};


		virtual agregarEje(int u, int v);

		//Getters
		V() {return V};
		E() {return E};

	protected:
		vector<vector<pair<int, bool> > > matriz;
		int V;
		int E;

};


//Ejercicio 1. Grafo no dirigido con peso en los ejes y un booleano que indica si la ruta es o no premium
class GrafoConPremium : public Grafo{
	public:
		//Crea un grafo vacio
		GrafoConPremium() {};
		
		//Crea un grafo con Ve vertices disconexos
		GrafoConPremium(int Ve);

		~GrafoConPremium() {};

		void agregarEje(int u, int v, int peso, bool premium);

	private:
		vector<vector<pair<int, bool> > > matriz;
		int V;
		int E;

};

//Ejercicio 2. Grafo dirigido con pesos.
class DigrafoConPeso : public Grafo{
	public:
		//Crea un grafo vacio
		GrafoConPeso() {};
		
		//Crea un grafo con Ve vertices disconexos
		GrafoConPeso(int Ve);

		~GrafoConPeso() {};

		void agregarEje(int u, int v, int peso);
	
	private:
		vector<vector<int> > matriz;
		int V;
		int E;

};

//Ejercicio 3. Grafo no dirigido con pesos.
class GrafoConPeso : public Grafo{
	public:
		//Crea un grafo vacio
		GrafoConPeso() {};
		
		//Crea un grafo con Ve vertices disconexos
		GrafoConPeso(int Ve);

		~GrafoConPeso() {};

		void agregarEje(int u, int v, int peso);

	private:
		vector<vector<int> > matriz;
		int V;
		int E;

};