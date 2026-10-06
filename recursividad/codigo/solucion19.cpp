#include <iostream>
#include <span>
using namespace std;
// Con span la recursion reduce el problema con first/last/subspan, sin pasar punteros ni 'n'
int suma(span<const int> v){
	return v.empty() ? 0 : v.front() + suma(v.subspan(1));
}
int maximo(span<const int> v){
	if (v.size() == 1) return v[0];
	int m = maximo(v.subspan(1));
	return v[0] > m ? v[0] : m;
}
// busqueda binaria recursiva: devuelve el indice relativo al span original
int binaria(span<const int> v, int clave, int desplazamiento = 0){
	if (v.empty()) return -1;
	size_t mid = v.size() / 2;
	if (v[mid] == clave) return desplazamiento + static_cast<int>(mid);
	if (clave < v[mid]) return binaria(v.first(mid), clave, desplazamiento);
	return binaria(v.subspan(mid + 1), clave, desplazamiento + static_cast<int>(mid) + 1);
}
void invertir(span<int> v){
	if (v.size() < 2) return;
	swap(v.front(), v.back());
	invertir(v.subspan(1, v.size() - 2));
}
bool esPalindromo(span<const char> v){
	if (v.size() < 2) return true;
	return v.front() == v.back() && esPalindromo(v.subspan(1, v.size() - 2));
}
int main(){
	int a[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
	cout << "Suma: " << suma(a) << ", maximo: " << maximo(a) << endl;
	cout << "Posicion de 23: " << binaria(a, 23) << ", de 91: " << binaria(a, 91)
	     << ", de 7: " << binaria(a, 7) << endl;
	cout << "Suma de los 4 primeros: " << suma(span(a).first(4)) << endl;
	invertir(a);
	for (int x : a) cout << x << " ";
	cout << endl;
	const char s[] = "reconocer";
	cout << boolalpha << esPalindromo(span<const char>(s, 9)) << endl;
	return 0;
}
