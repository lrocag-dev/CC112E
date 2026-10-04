#include <iostream>
#include <algorithm>
#include <concepts>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
// Algoritmos genericos: funcionan con arreglos, vector, deque, etc.
template <random_access_iterator It, typename Comp = ranges::less>
requires sortable<It, Comp>
void insercion(It ini, It fin, Comp comp = {}){
	for (It i = ini + 1; i < fin; ++i){
		auto x = std::move(*i);
		It j = i;
		while (j > ini && comp(x, *(j - 1))){
			*j = std::move(*(j - 1));
			--j;
		}
		*j = std::move(x);
	}
}
template <forward_iterator It, typename T, typename Comp = ranges::less>
It busquedaBinaria(It ini, It fin, const T &clave, Comp comp = {}){
	auto n = distance(ini, fin);
	while (n > 0){
		auto mitad = n / 2;
		It m = ini;
		advance(m, mitad);
		if (comp(*m, clave)){ ini = ++m; n -= mitad + 1; }
		else n = mitad;
	}
	return (ini != fin && !comp(clave, *ini)) ? ini : fin;
}
template <typename C>
void mostrar(const C &c){ for (const auto &x : c) cout << x << " "; cout << endl; }

int main(){
	int a[] = {5, 2, 9, 1, 7, 3};
	insercion(begin(a), end(a));
	mostrar(a);

	vector<string> nombres = {"Rosa", "Luis", "Ana", "Pedro", "Beto"};
	insercion(nombres.begin(), nombres.end());
	mostrar(nombres);
	insercion(nombres.begin(), nombres.end(), ranges::greater{});
	mostrar(nombres);
	insercion(nombres.begin(), nombres.end(), [](const string &x, const string &y){ return x.size() < y.size(); });
	cout << "Por longitud: ";
	mostrar(nombres);

	insercion(begin(a), end(a));
	auto it = busquedaBinaria(begin(a), end(a), 7);
	cout << "7 en la posicion " << it - begin(a) << endl;
	cout << "8 " << (busquedaBinaria(begin(a), end(a), 8) == end(a) ? "no esta" : "esta") << endl;
	// insercion(list<int>...) -> ERROR de compilacion: list no tiene iteradores de acceso aleatorio
	return 0;
}
