#include <iostream>
#include <array>
#include <span>
using namespace std;
// Punteros y arreglos en tiempo de compilacion
constexpr int sumaPtr(const int *ini, const int *fin){
	int s = 0;
	for (const int *p = ini; p != fin; ++p) s += *p;
	return s;
}
constexpr int NUM = 8;
constexpr array<int, NUM> datos = {3, 1, 4, 1, 5, 9, 2, 6};
constexpr int TOTAL = sumaPtr(datos.data(), datos.data() + datos.size());
static_assert(TOTAL == 31, "la suma debe ser 31");

// consteval: se EJECUTA obligatoriamente en compilacion
consteval array<int, NUM> tablaCuadrados(){
	array<int, NUM> t{};
	for (int i = 0; i < NUM; i++) t[i] = i * i;
	return t;
}
constexpr auto cuadrados = tablaCuadrados();

constexpr const int *buscar(span<const int> v, int clave){
	for (const int *p = v.data(); p != v.data() + v.size(); ++p)
		if (*p == clave) return p;
	return nullptr;
}
constexpr bool hay9 = buscar(datos, 9) != nullptr;
static_assert(hay9);

int main(){
	cout << "TOTAL calculado en compilacion: " << TOTAL << endl;
	cout << "Cuadrados: ";
	for (int x : cuadrados) cout << x << " ";
	cout << endl;
	int n;
	cout << "Valor a buscar: ";
	cin >> n;
	const int *r = buscar(datos, n);          // misma funcion, ahora en ejecucion
	if (r) cout << "Posicion: " << r - datos.data() << endl;
	else cout << "No existe" << endl;
	// int *w = &datos[0]; *w = 0;            // ERROR: datos es constante
	return 0;
}
