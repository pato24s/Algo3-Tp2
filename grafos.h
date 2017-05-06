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
}

class GrafoConPeso{
	public:
		//Crea un grafo vacio
		GrafoConPeso();
		
		//Crea un grafo con V vertices disconexos
		GrafoConPeso(int V);

		~GrafoConPeso() {};

		void agregarEje(eje e);

	private:
		vector<vector<int> > matriz;
		int V;
		int E;

}

class GrafoConPremium{
	public:
		//Crea un grafo vacio
		GrafoConPremium();
		
		//Crea un grafo con V vertices disconexos
		GrafoConPremium(int V);

		~GrafoConPremium() {};

		void agregarEje(eje e);

	private:
		vector<vector<pair<int, bool> > > matriz;
		int V;
		int E;

}