#include <iostream>
#include <span>
#include <algorithm>
using namespace std;
// span = puntero + tamano en un solo objeto: ya no hace falta pasar 'n'
int suma(span<const int> v){
	int s = 0;
	for (int x : v) s += x;
	return s;
}
void invertir(span<int> v){
	for (size_t i = 0; i < v.size() / 2; i++)
		swap(v[i], v[v.size() - 1 - i]);
}
void mostrar(span<const int> v){
	for (int x : v) cout << x << " ";
	cout << endl;
}
int main(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	cout << "Suma total: " << suma(a) << endl;                 // arreglo -> span automatico
	cout << "Suma de los 3 primeros: " << suma(span(a).first(3)) << endl;
	cout << "Suma de los 3 ultimos: " << suma(span(a).last(3)) << endl;
	span<int> medio = span(a).subspan(2, 4);                    // a[2..5]
	invertir(medio);                                            // modifica el arreglo original
	mostrar(a);
	cout << "Elementos: " << medio.size() << ", bytes: " << medio.size_bytes() << endl;
	cout << "Primer elemento del span: " << medio.front() << " (direccion " << medio.data() << ")" << endl;
	return 0;
}
