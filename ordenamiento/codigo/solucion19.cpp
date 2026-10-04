#include <iostream>
#include <algorithm>
#include <compare>
#include <functional>
#include <string>
#include <vector>
using namespace std;
struct Version {
	int mayor, menor, parche;
	auto operator<=>(const Version &) const = default;
	friend ostream &operator<<(ostream &o, const Version &v){ return o << v.mayor << "." << v.menor << "." << v.parche; }
};
struct Jugador {
	string nombre;
	int puntos;
	int tiempo;
	// criterio: mas puntos primero; si empatan, menos tiempo
	strong_ordering operator<=>(const Jugador &o) const {
		if (auto c = o.puntos <=> puntos; c != 0) return c;
		return tiempo <=> o.tiempo;
	}
	bool operator==(const Jugador &o) const { return puntos == o.puntos && tiempo == o.tiempo; }
};
// algoritmo generico que usa <=>: ordena y elimina duplicados equivalentes
template <typename T>
void ordenar(vector<T> &v){
	ranges::sort(v, [](const T &a, const T &b){ return (a <=> b) < 0; });
}
int main(){
	vector<Version> vs = {{1, 10, 0}, {1, 2, 5}, {2, 0, 0}, {1, 2, 10}, {0, 9, 9}};
	ordenar(vs);
	for (const auto &v : vs) cout << v << " ";
	cout << endl;

	vector<Jugador> ranking = {{"Ana", 90, 300}, {"Luis", 95, 410}, {"Rosa", 90, 280}, {"Beto", 95, 390}, {"Eva", 70, 100}};
	ranges::sort(ranking);                                   // usa operator<=> del struct
	int puesto = 1;
	for (const auto &j : ranking)
		cout << puesto++ << ". " << j.nombre << " " << j.puntos << " pts " << j.tiempo << " s" << endl;

	compare_three_way cmp;                                    // objeto-funcion que invoca <=>
	const Jugador &x = ranking[3], &y = ranking[2];
	cout << x.nombre << " vs " << y.nombre << ": " << (cmp(x, y) < 0 ? x.nombre : y.nombre) << " va primero" << endl;
	cout << boolalpha << "is_sorted: " << ranges::is_sorted(ranking) << endl;
	cout << "Mejor: " << ranges::min_element(ranking)->nombre << endl;

	auto r = string("manzana") <=> string("mango");
	cout << "manzana <=> mango: " << (r < 0 ? "menor" : r > 0 ? "mayor" : "igual") << endl;
	auto r2 = 2.5 <=> 2.5;
	cout << "2.5 <=> 2.5 es " << (r2 == 0 ? "equivalente" : "distinto") << endl;
	return 0;
}
