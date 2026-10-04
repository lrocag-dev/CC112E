#include <iostream>
#include <algorithm>
#include <ranges>
#include <span>
using namespace std;
struct Producto { const char *nombre; double precio; };
int main(){
	int a[] = {42, 7, 19, 3, 88, 25, 7};
	span<int> v(a);

	ranges::sort(v);                                   // sin pasar begin/end
	for (int x : v) cout << x << " ";
	cout << endl;

	ranges::sort(v, ranges::greater{});                // orden descendente
	for (int x : v) cout << x << " ";
	cout << endl;

	auto [mn, mx] = ranges::minmax(v);                 // minimo y maximo
	cout << "min=" << mn << " max=" << mx << endl;

	if (auto it = ranges::find(v, 19); it != v.end())   // 'it' es un iterador (puntero)
		cout << "19 en la posicion " << it - v.begin() << endl;

	ranges::reverse(v);
	ranges::rotate(v, v.begin() + 2);                  // rota a la izquierda 2 posiciones
	for (int x : v) cout << x << " ";
	cout << endl;

	cout << "Pares: ";
	for (int x : v | views::filter([](int n){ return n % 2 == 0; }))
		cout << x << " ";
	cout << endl;

	Producto p[] = {{"Lapiz", 1.5}, {"Cuaderno", 6.0}, {"Borrador", 0.8}};
	ranges::sort(p, {}, &Producto::precio);            // proyeccion: ordena por precio
	for (const auto &x : p) cout << x.nombre << " " << x.precio << endl;
	return 0;
}
