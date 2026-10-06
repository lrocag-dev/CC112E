#include <iostream>
#include <algorithm>
#include <array>
#include <string_view>
using namespace std;
// Ordenamiento ejecutado durante la compilacion
template <typename T, size_t N>
constexpr array<T, N> burbuja(array<T, N> a){
	for (size_t i = 0; i + 1 < N; i++)
		for (size_t j = 0; j + 1 < N - i; j++)
			if (a[j] > a[j + 1]){
				T aux = a[j]; a[j] = a[j + 1]; a[j + 1] = aux;
			}
	return a;
}
template <typename T, size_t N>
constexpr int busquedaBinaria(const array<T, N> &a, T clave){
	int ini = 0, fin = static_cast<int>(N) - 1;
	while (ini <= fin){
		int mid = ini + (fin - ini) / 2;
		if (a[mid] == clave) return mid;
		if (a[mid] < clave) ini = mid + 1; else fin = mid - 1;
	}
	return -1;
}
constexpr array<int, 8> DESORDENADO = {42, 7, 19, 3, 88, 25, 61, 14};
constexpr auto ORDENADO = burbuja(DESORDENADO);
static_assert(ranges::is_sorted(ORDENADO));
static_assert(ORDENADO[0] == 3 && ORDENADO[7] == 88);
static_assert(busquedaBinaria(ORDENADO, 25) == 4);
static_assert(busquedaBinaria(ORDENADO, 26) == -1);

// std::ranges::sort tambien es constexpr desde C++20
constexpr auto ordenadoStd(){
	auto a = DESORDENADO;
	ranges::sort(a, ranges::greater{});
	return a;
}
constexpr auto DESCENDENTE = ordenadoStd();
static_assert(DESCENDENTE[0] == 88);

// tabla de palabras reservadas ordenada en compilacion para buscarla luego en O(log n)
constexpr array<string_view, 6> PALABRAS = burbuja(array<string_view, 6>{"while", "int", "for", "return", "if", "double"});
static_assert(ranges::is_sorted(PALABRAS));

int main(){
	cout << "Ordenado en compilacion:   ";
	for (int x : ORDENADO) cout << x << " ";
	cout << endl << "Descendente (std::ranges): ";
	for (int x : DESCENDENTE) cout << x << " ";
	cout << endl << "Palabras:";
	for (auto p : PALABRAS) cout << " " << p;
	cout << endl;
	string_view clave = "return";
	cout << "'return' es palabra reservada? " << boolalpha << ranges::binary_search(PALABRAS, clave) << endl;
	cout << "'main' es palabra reservada? " << ranges::binary_search(PALABRAS, string_view("main")) << endl;
	cout << "Posicion de 61 en el arreglo ordenado: " << busquedaBinaria(ORDENADO, 61) << endl;
	return 0;
}
