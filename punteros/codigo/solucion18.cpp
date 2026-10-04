#include <iostream>
#include <concepts>
#include <span>
using namespace std;
// Alternativa segura a void*: plantillas con restricciones (concepts)
template <typename T>
void intercambiar(T *a, T *b){
	T aux = *a;
	*a = *b;
	*b = aux;
}
template <typename T>
concept Numerico = integral<T> || floating_point<T>;

template <Numerico T>
T suma(span<const T> v){
	T s{};
	for (T x : v) s += x;
	return s;
}
template <Numerico T>
double promedio(span<const T> v){
	return v.empty() ? 0.0 : static_cast<double>(suma(v)) / v.size();
}
template <integral T>
bool esPar(T x){ return x % 2 == 0; }

template <typename T>
requires totally_ordered<T>
const T *mayor(span<const T> v){
	if (v.empty()) return nullptr;
	const T *m = v.data();
	for (const T *p = v.data() + 1; p < v.data() + v.size(); p++)
		if (*p > *m) m = p;
	return m;
}
int main(){
	int x = 1, y = 2;
	double u = 1.5, v = 9.5;
	intercambiar(&x, &y);
	intercambiar(&u, &v);
	cout << x << " " << y << " " << u << " " << v << endl;

	int a[] = {4, 8, 15, 16, 23, 42};
	double b[] = {1.5, 2.5, 3.0};
	cout << "Suma int: " << suma<int>(a) << ", promedio: " << promedio<int>(a) << endl;
	cout << "Suma double: " << suma<double>(b) << ", promedio: " << promedio<double>(b) << endl;
	cout << "42 es par: " << boolalpha << esPar(42) << endl;
	// esPar(2.5);   // ERROR de compilacion: double no cumple 'integral'
	// suma<string>  // ERROR de compilacion: string no es Numerico
	cout << "Mayor: " << *mayor<int>(a) << ", " << *mayor<double>(b) << endl;
	return 0;
}
