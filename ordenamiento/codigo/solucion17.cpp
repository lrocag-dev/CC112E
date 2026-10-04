#include <iostream>
#include <algorithm>
#include <span>
#include <vector>
using namespace std;
int main(){
	vector<int> v = {1, 3, 3, 3, 5, 8, 8, 13, 21, 34, 55, 89};
	span<const int> s(v);

	cout << boolalpha << "binary_search(13): " << ranges::binary_search(s, 13) << ", (14): "
	     << ranges::binary_search(s, 14) << endl;

	auto lo = ranges::lower_bound(s, 3);                 // primer elemento >= 3
	auto hi = ranges::upper_bound(s, 3);                 // primer elemento > 3
	cout << "3 aparece " << hi - lo << " veces, desde la posicion " << lo - s.begin() << endl;

	auto [ini, fin] = ranges::equal_range(s, 8);
	cout << "equal_range(8): posiciones " << ini - s.begin() << " a " << fin - s.begin() - 1 << endl;

	// donde insertar manteniendo el orden
	int nuevo = 10;
	auto pos = ranges::lower_bound(v, nuevo);
	v.insert(pos, nuevo);
	for (int x : v) cout << x << " ";
	cout << endl;

	// busqueda binaria con proyeccion sobre un struct
	struct Producto { int id; const char *nombre; };
	Producto catalogo[] = {{101, "Lapiz"}, {205, "Cuaderno"}, {310, "Regla"}, {412, "Mochila"}};
	auto it = ranges::lower_bound(catalogo, 310, {}, &Producto::id);
	if (it != end(catalogo) && it->id == 310) cout << "Producto 310: " << it->nombre << endl;

	// sub-rango con span: buscar solo entre las posiciones 4 y 9
	auto parte = s.subspan(4, 6);
	cout << "21 en el sub-rango: " << ranges::binary_search(parte, 21)
	     << ", 3 en el sub-rango: " << ranges::binary_search(parte, 3) << endl;
	return 0;
}
